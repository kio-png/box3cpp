#include <box3cpp/box3cpp.hpp>

int main() {
    static_assert(box3cpp::version_major == 0);
    static_assert(box3cpp::version_minor == 1);
    static_assert(box3cpp::version_patch == 0);

    return 0;
}
