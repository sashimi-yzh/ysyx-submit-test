#ifndef __FMT_DEF_H_
#define __FMT_DEF_H_



#ifdef CONFIG_RV64
#define FMT_WORD_HEX "%lx"
#define FMT_WORD_INT "%ld"
#define FMT_WORD_HEX_WIDTH "%016lx"
#define FMT_WORD_UINT "%lu"

#else
#define FMT_WORD_HEX "%x"
#define FMT_WORD_INT "%d"
#define FMT_WORD_HEX_WIDTH "%08x"
#define FMT_WORD_UINT "%u"

#endif 


#endif // !__FMT_DEF_H_
