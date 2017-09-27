/*
 ============================================================================
 Name        : hev-task-io.h
 Author      : Heiher <r@hev.cc>
 Copyright   : Copyright (c) 2017 everyone.
 Description : Task I/O operations
 ============================================================================
 */

#ifndef __HEV_TASK_IO_H__
#define __HEV_TASK_IO_H__

#include <unistd.h>

#include "hev-task.h"

typedef int (*HevTaskIOYielder) (HevTaskYieldType type, void *data);

ssize_t hev_task_io_read (int fd, void *buf, size_t count,
			HevTaskIOYielder yielder, void *yielder_data);

ssize_t hev_task_io_write (int fd, const void *buf, size_t count,
			HevTaskIOYielder yielder, void *yielder_data);

void hev_task_io_splice (int fd_a_i, int fd_a_o, int fd_b_i, int fd_b_o, size_t buf_size,
			HevTaskIOYielder yielder, void *yielder_data);

#endif /* __HEV_TASK_IO_H__ */
