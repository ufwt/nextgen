/*
 * Copyright (c) 2016, Harrison Bowden, Minneapolis, MN
 *
 * Permission to use, copy, modify, and/or distribute this software for any purpose
 * with or without fee is hereby granted, provided that the above copyright notice
 * and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
 * WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include "unity.h"
#include "syscall/child.c"

static void test_get_syscall_child(void)
{
    int32_t rtrn = 0;
    struct syscall_child *child = NULL;

    struct output_writter *output = get_console_writter();
    struct memory_allocator *allocator = get_default_allocator();

    child = get_syscall_child(allocator, output);
    TEST_ASSERT_NOT_NULL(child);

    rtrn = child->setup();
    TEST_ASSERT(rtrn == 0);

    rtrn = child->start();
    TEST_ASSERT(rtrn == 0);

    return;
}

int main(void)
{
    test_get_syscall_child();
    return (0);
}
