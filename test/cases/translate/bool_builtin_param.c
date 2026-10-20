#define FOO (1 > 0)
int bar(void *p) {
    return __builtin_object_size(p, (0 > 0) && FOO);
}

// translate
//
// pub export fn bar(arg_p: ?*anyopaque) c_int {
//     var p = arg_p;
//     _ = &p;
//     return @bitCast(@as(c_uint, @truncate(__builtin.object_size(p, @as(c_int, @intFromBool((@as(c_int, 0) > @as(c_int, 0)) and (@as(c_int, 1) > @as(c_int, 0))))))));
// }
