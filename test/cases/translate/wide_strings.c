#include <wchar.h>
#include <stdint.h>
void foo() {
    wchar_t *a = L"foo";
    wchar_t b[] = L"foo";
    uint32_t const *c = U"foo";
    uint32_t d[] = U"foo";
}

// translate
//
// pub export fn foo() void {
//     var a: [*c]wchar_t = @constCast(&([3:0]c_int{
//         '\u{66}',
//         '\u{6f}',
//         '\u{6f}',
//     }));
//     _ = &a;
//     var b: [3:0]wchar_t = [3:0]wchar_t{
//         '\u{66}',
//         '\u{6f}',
//         '\u{6f}',
//     };
//     _ = &b;
//     var c: [*c]const u32 = &([3:0]c_uint{
//         '\u{66}',
//         '\u{6f}',
//         '\u{6f}',
//     });
//     _ = &c;
//     var d: [3:0]u32 = [3:0]u32{
//         '\u{66}',
//         '\u{6f}',
//         '\u{6f}',
//     };
//     _ = &d;
// }
