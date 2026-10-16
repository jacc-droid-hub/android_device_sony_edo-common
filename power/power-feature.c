/*
 * Copyright (C) 2026
 * SPDX-License-Identifier: Apache-2.0
 */

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#include <hardware/power.h>
#include <log/log.h>

static void write_sysfs(const char *path, const char *value) {
    int fd = open(path, O_WRONLY | O_CLOEXEC);
    if (fd < 0) {
        ALOGE("DT2W: cannot open %s: %s", path, strerror(errno));
        return;
    }

    const size_t len = strlen(value);
    const ssize_t written = write(fd, value, len);
    if (written != (ssize_t)len) {
        ALOGE("DT2W: write to %s failed: %s", path,
              written < 0 ? strerror(errno) : "short write");
    }

    close(fd);
}

void set_device_specific_feature(feature_t feature, int state) {
    switch (feature) {
        case POWER_FEATURE_DOUBLE_TAP_TO_WAKE:
            write_sysfs("/sys/devices/virtual/sec/tsp/cmd",
                        state ? "sod_enable,1" : "sod_enable,0");
            write_sysfs("/sys/devices/dsi_panel_driver/pre_sod_mode",
                        state ? "1" : "0");
            break;

        default:
            break;
    }
}
