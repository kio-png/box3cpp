# Ownership rules

This note describes the first ownership model for `box3cpp`.

The goal is to keep Box3D lifetimes visible while making common C++ usage safer. The wrapper should make it clear which objects own resources, which objects are handles, and what becomes invalid when a parent object is destroyed.

## World

`World` is the root owner in the wrapper. It owns the native Box3D world resource and releases it in its destructor.

`World` should not be copyable. Copying a physics world would make ownership unclear and could suggest a deep copy that the wrapper does not provide.

The intended direction is for `World` to become move-only. Moving a `World` should transfer ownership of the native resource and leave the moved-from object empty but safe to destroy.

Child handles should not depend on the C++ address of `World`. If moving `World` would make existing body or shape handles unsafe, move support should wait until the handle model is clear.

## Body, Shape, and Joint

`Body`, `Shape`, and `Joint` should start as lightweight handles. They refer to objects that live inside a `World`, but they do not own the world itself.

These types should not be copyable at first. Copyable handles can be considered later only if their invalidation rules stay simple.

A handle becomes invalid when the underlying Box3D object is destroyed or when the owning `World` is destroyed. The wrapper should document this clearly instead of pretending that a handle can keep a native object alive.

Move construction and move assignment should be allowed when they only transfer the handle value. A moved-from handle should become empty and safe to destroy.

## Destruction and invalidation

Destruction should follow the same parent-child order as Box3D.

Destroying a `World` invalidates every `Body`, `Shape`, and `Joint` handle created from it. Destroying a `Body` invalidates handles to shapes and joints that depend on that body.

The wrapper should not try to keep child objects alive after their parent resource is gone. That would hide the real Box3D lifetime model and make errors harder to reason about.

The first version should prefer simple rules over clever safety checks. Debug assertions can be added later if they help catch invalid handle use without making the wrapper heavy.

## First pass

For the first implementation, the rules should stay conservative.

- `World` owns the native Box3D world resource
- `Body`, `Shape`, and `Joint` are non-owning handles
- all wrapper types are non-copyable at first
- move operations leave the moved-from object empty
- destroying a parent resource invalidates its child handles
- destructors only release resources for objects that actually own something

These rules can be relaxed later if real examples show that copyable handles or extra lifetime tracking are worth the complexity.
