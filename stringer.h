/**
 *  @file stringer.h
 *  @version 0.3.0-dev0
 *  @date Sun Feb 16, 2020 05:10:21 PM CST
 *  @copyright 2020 John A. Crow <crowja@gmail.com>
 *  @license Unlicense <http://unlicense.org/>
 */

#ifndef STRINGER_H
#define STRINGER_H

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
 *  @brief Return the version of this package.
 *  @returns Version string.
 */
const char *stringer_version(void);

int         stringer_empty(struct stringer *p);
int         stringer_insert(struct stringer *p, char *s);
int         stringer_strings(struct stringer *p, unsigned *n, char ***cpp);

#endif
