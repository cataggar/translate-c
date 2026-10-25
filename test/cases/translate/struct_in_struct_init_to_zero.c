struct Foo {
    int a;
    struct Bar {
        int a;
    } b;
} a = {};

// translate
// args = -fdefault-init
//
// pub const struct_Bar_1 = extern struct {
//     a: c_int = 0,
// };
// pub const struct_Foo = extern struct {
//     a: c_int = 0,
//     b: struct_Bar_1 = __helpers.zeroes(struct_Bar_1),
// };
// pub export var a: struct_Foo = struct_Foo{
//     .a = 0,
//     .b = __helpers.zeroes(struct_Bar_1),
// };
