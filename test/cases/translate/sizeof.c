#include <stddef.h>
size_t size_of(void) {
        return sizeof(int);
}
size_t size_of_expr(void) {
        return sizeof 1;
}
#define sizeof_macro(x) sizeof(x)

extern void func(int i, ...);
void foo() {
    func(0, sizeof(int));
}

void maxsize(int negative){
    static char const min[] = "-9223372036854775808";
    static char const max[] = "9223372036854775807";
    unsigned int const maxdigits = (negative ? sizeof(min): sizeof(max));
}

// translate
// target = x86_64-linux
//
// pub export fn size_of() usize {
//     return @sizeOf(c_int);
// }
//
// pub export fn size_of_expr() usize {
//     return @sizeOf(@TypeOf(@as(c_int, 1)));
// }
//
// pub inline fn sizeof_macro(x: anytype) @TypeOf(__helpers.sizeof(x)) {
//     _ = &x;
//     return __helpers.sizeof(x);
// }
//
// pub export fn foo() void {
//     func(0, @as(usize, @sizeOf(c_int)));
// }
//
// pub export fn maxsize(arg_negative: c_int) void {
//     var negative = arg_negative;
//     _ = &negative;
//     const static_local_min = struct {
//         const min: [21]c_char = @as(*const [21]c_char, @ptrCast("-9223372036854775808")).*;
//     };
//     _ = &static_local_min;
//     const static_local_max = struct {
//         const max: [20]c_char = @as(*const [20]c_char, @ptrCast("9223372036854775807")).*;
//     };
//     _ = &static_local_max;
//     const maxdigits: c_uint = @truncate(if (negative != 0) @as(usize, @sizeOf(@TypeOf(static_local_min.min))) else @as(usize, @sizeOf(@TypeOf(static_local_max.max))));
//     _ = &maxdigits;
// }
