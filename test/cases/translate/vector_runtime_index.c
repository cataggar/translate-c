typedef int vec __attribute__((vector_size(4 * 8)));

int foo(vec a, int i) {
    a[i] = 1;
    a[i] += 2;
    i = a[i] = 3;
    i = a[i] += 4;
    return a[i];
}

// translate
//
// pub const vec = @Vector(8, c_int);
// pub export fn foo(arg_a: vec, arg_i: c_int) c_int {
//     var a = arg_a;
//     _ = &a;
//     var i = arg_i;
//     _ = &i;
//     __helpers.vectorIndexStore(&a, i, 1);
//     {
//         const tmp_base = &a;
//         const tmp_index = i;
//         const new = __helpers.vectorIndexLoad(tmp_base.*, tmp_index) + @as(c_int, 2);
//         __helpers.vectorIndexStore(tmp_base, tmp_index, new);
//     }
//     i = blk: {
//         const tmp_base = &a;
//         const tmp_index = i;
//         const new = @as(c_int, 3);
//         __helpers.vectorIndexStore(tmp_base, tmp_index, new);
//         break :blk new;
//     };
//     i = blk: {
//         const tmp_base = &a;
//         const tmp_index = i;
//         const new = __helpers.vectorIndexLoad(tmp_base.*, tmp_index) + @as(c_int, 4);
//         __helpers.vectorIndexStore(tmp_base, tmp_index, new);
//         break :blk new;
//     };
//     return __helpers.vectorIndexLoad(a, i);
// }
