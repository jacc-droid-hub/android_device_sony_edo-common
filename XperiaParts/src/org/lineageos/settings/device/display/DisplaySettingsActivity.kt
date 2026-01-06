/*
 * Copyright (C) 2022 The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

package org.lineageos.settings.device.display

import android.app.Activity
import android.os.Bundle

class DisplaySettingsActivity : Activity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        fragmentManager.beginTransaction()
            .replace(android.R.id.content, DisplaySettingsFragment(), TAG)
            .commit()
    }

    companion object {
        private const val TAG = "CreatorModeSettingsActivity"
    }
}
