#ifndef __DINAMIC_STRING__
#define __DINAMIC_STRING__

#define dstring char*
#define TOCHAR (char*)
#define UNINT unsigned int

dstring dstr_init(void);
void dstr_addc(dstring *dstr, char c);
void dstr_copy(dstring dest, const char *src);
void dstr_merge(dstring *dest, const char *src);
void dstr_end(dstring *dstr);

#endif
