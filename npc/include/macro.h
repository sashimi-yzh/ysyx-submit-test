#ifndef NPC_MACRO_H
#define NPC_MACRO_H

#define NPC_STRINGIFY_INNER(value) #value
#define str(value) NPC_STRINGIFY_INNER(value)

#define NPC_CONCAT_INNER(left, right) left ## right
#define concat(left, right) NPC_CONCAT_INNER(left, right)

#define ARRLEN(array) ((int)(sizeof(array) / sizeof((array)[0])))

#define NPC_SELECT_SECOND(first, second, ...) second
#define NPC_SELECT_COMMA(has_comma, yes, no) NPC_SELECT_SECOND(has_comma yes, no)
#define NPC_MACRO_PROPERTY(prefix, macro, yes, no) \
  NPC_SELECT_COMMA(concat(prefix, macro), yes, no)

#define NPC_DEFINED_0 X,
#define NPC_DEFINED_1 X,
#define MUXDEF(macro, yes, no) \
  NPC_MACRO_PROPERTY(NPC_DEFINED_, macro, yes, no)

#define NPC_IGNORE(...)
#define NPC_KEEP(...) __VA_ARGS__
#define IFDEF(macro, ...) MUXDEF(macro, NPC_KEEP, NPC_IGNORE)(__VA_ARGS__)

#define BITMASK(width) ((1ull << (width)) - 1)
#define BITS(value, high, low) \
  (((value) >> (low)) & BITMASK((high) - (low) + 1))

#if !defined(likely)
#define likely(condition) __builtin_expect((condition), 1)
#endif

#endif
