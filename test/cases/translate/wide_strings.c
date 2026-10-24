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
//     var a: [*c]wchar_t = @constCast(&([3]c_int{
//         '\u{66}',
//         '\u{6f}',
//         '\u{6f}',
//     } ++ @as([1]c_int, @splat(0))));
//     _ = &a;
//     var b: [4]wchar_t = [3]wchar_t{
//         '\u{66}',
//         '\u{6f}',
//         '\u{6f}',
//     } ++ @as([1]wchar_t, @splat(0));
//     _ = &b;
//     var c: [*c]const u32 = &([3]c_uint{
//         '\u{66}',
//         '\u{6f}',
//         '\u{6f}',
//     } ++ @as([1]c_uint, @splat(0)));
//     _ = &c;
//     var d: [4]u32 = [3]u32{
//         '\u{66}',
//         '\u{6f}',
//         '\u{6f}',
//     } ++ @as([1]u32, @splat(0));
//     _ = &d;
// }
