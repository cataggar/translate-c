#include <stdint.h>
char zero[0] = "abc";
uint32_t zero_w[0] = U"💯💯💯";
char empty_incomplete[] = "";
uint32_t empty_incomplete_w[] = U"";
char empty_constant[100] = "";
uint32_t empty_constant_w[100] = U"";
char incomplete[] = "abc";
uint32_t incomplete_w[] = U"💯💯💯";
char truncated[1] = "abc";
uint32_t truncated_w[1] = U"💯💯💯";
char extend[5] = "a";
uint32_t extend_w[5] = U"💯";
char no_null[3] = "abc";
uint32_t no_null_w[3] = U"💯💯💯";

// translate
//
// pub export var zero: [0]c_char = [0]c_char{};
// pub export var zero_w: [0]u32 = [0]u32{};
// pub export var empty_incomplete: [1]c_char = @as([1]c_char, @splat(0));
// pub export var empty_incomplete_w: [1]u32 = @as([1]u32, @splat(0));
// pub export var empty_constant: [100]c_char = @as([100]c_char, @splat(0));
// pub export var empty_constant_w: [100]u32 = @as([100]u32, @splat(0));
// pub export var incomplete: [4]c_char = @as(*const [4]c_char, @ptrCast("abc")).*;
// pub export var incomplete_w: [4]u32 = [3]u32{
//     '\u{1f4af}',
//     '\u{1f4af}',
//     '\u{1f4af}',
// } ++ @as([1]u32, @splat(0));
// pub export var truncated: [1]c_char = @as(*const [3:0]c_char, @ptrCast("abc"))[0..1].*;
// pub export var truncated_w: [1]u32 = [1]u32{
//     '\u{1f4af}',
// };
// pub export var extend: [5]c_char = @as(*const [1:0]c_char, @ptrCast("a"))[0..1].* ++ @as([4]c_char, @splat(0));
// pub export var extend_w: [5]u32 = [1]u32{
//     '\u{1f4af}',
// } ++ @as([4]u32, @splat(0));
// pub export var no_null: [3]c_char = @as(*const [3:0]c_char, @ptrCast("abc")).*;
// pub export var no_null_w: [3]u32 = [3]u32{
//     '\u{1f4af}',
//     '\u{1f4af}',
//     '\u{1f4af}',
// };
