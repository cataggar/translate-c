typedef short int16_t;

static int16_t f(int16_t x) {
    return x;
}

int foo(void) {
    int16_t x = f((1 >= 0, 2 == 2));
    return x;
}

// translate
//
// pub fn f(arg_x: i16) callconv(.c) i16 {
//     var x = arg_x;
//     _ = &x;
//     return x;
// }
// pub export fn foo() c_int {
//     var x: i16 = f(@truncate(blk: {
//         _ = @as(c_int, 1) >= @as(c_int, 0);
//         break :blk @as(c_int, @intFromBool(@as(c_int, 2) == @as(c_int, 2)));
//     }));
//     _ = &x;
//     return x;
// }
