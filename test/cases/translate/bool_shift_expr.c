int shift(int a) {
    return !!(a) << 1;
}

// translate
//
// pub export fn shift(arg_a: c_int) c_int {
//     var a = arg_a;
//     _ = &a;
//     return @as(c_int, @intFromBool(!!(a != 0))) << @intCast(@as(c_int, 1));
// }
