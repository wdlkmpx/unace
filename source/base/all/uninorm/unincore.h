/*
 * Header file to use Uninorm library
 *
 */

/* integer string functions                             */
int    istrlen                  (int  * str             );
int    istrcmp                  (int  * s1,  int  * s2  );

/* unicode data accessors                               */
int    is_excluded              (int    c               );
int    get_combining_class      (int    c               );
int    get_recombined_codepoint (int    c1,  int    c2  );
int  * get_decomposition        (int  * buf, int    c   );

/* utf en/decoding functions                            */
void encode_utf8(char *buf, unsigned *str);
void decode_utf8(unsigned *buf, char *str);

/* (de)composition functions                            */
void decompose_recursive      (int  * buf, int    c   );
void canonical_order          (int  * str             );
void canonical_composition    (int  * str             );
void canonical_decomposition  (int  * buf, int  * str );

/* normalization functions                              */
void normalize_nfd            (int  * buf, int  * str );
void normalize_nfc            (int  * buf, int  * str );
void normalize_nfd_utf8       (char * buf, char * str );
void normalize_nfc_utf8       (char * buf, char * str );
