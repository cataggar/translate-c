#pragma pack(push, 1)
struct foo
{
  char a;
  int b;
  char c;
};
#pragma pack(pop)

#pragma pack(push, 2)
struct bar {
    char a;
    int b;
    long long c;
};
#pragma pack(pop)

#pragma pack(push, 4)
struct baz {
    char a;
    double b;
    short c;
};
#pragma pack(pop)

struct horch {
    char a;
    int b;
    char c;
};

// translate
//
// pub const struct_foo = extern struct {
//     a: c_char align(1),
//     b: c_int align(1),
//     c: c_char,
// };
//
// pub const foo = struct_foo;
//
// pub const struct_bar = extern struct {
//     a: c_char align(2),
//     b: c_int align(2),
//     c: c_longlong align(1),
// };
//
// pub const bar = struct_bar;
//
// pub const struct_baz = extern struct {
//     a: c_char align(4),
//     b: f64 align(4),
//     c: c_short,
// };
//
// pub const baz = struct_baz;
//
// pub const struct_horch = extern struct {
//     a: c_char,
//     b: c_int,
//     c: c_char,
// };
//
// pub const horch = struct_horch;
