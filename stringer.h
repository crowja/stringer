/**
 *  @file stringer.h
 *  @version 0.0.0
 *  @date Mon Dec 30 13:23:52 CST 2019
 *  @copyright %COPYRIGHT%
 *  @brief FIXME
 *  @details FIXME
 */

#ifndef _STRINGER_H_
#define _STRINGER_H_

#ifdef  _PACKAGE_NAME
#undef  _PACKAGE_NAME
#endif
#define _PACKAGE_NAME "stringer"

struct stringer;

/**
 *  @brief Constructor.
 *  @details Create and return a new stringer object.
 *  @returns New stringer object.
 */
struct stringer *stringer_new(void);

/**
 *  @brief Destructor.
 *  @details Clean up and free a stringer structure.
 *  @param[in, out] p.
 */
void        stringer_free(struct stringer **pp);

/**
 *  @brief Initialize a stringer object.
 *  @details FIXME longer description here ...
 *  @param[in,out] p Pointer to a stringer object
 *  @param[in] x FIXME
    @returns FIXME
 */
int         stringer_init(struct stringer *p, void *x);

/**
 *  @brief Return the version of this package.
 *  @returns Version string.
 */
const char *stringer_version(void);

int         stringer_empty(struct stringer *p);
int         stringer_insert(struct stringer *p, char *s);
char      **stringer_strings(struct stringer *p);

#endif
