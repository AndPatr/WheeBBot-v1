/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2018-2019 Erik Moqvist
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * This file was generated by cantools version 36.7.0 Sun Feb  6 13:22:53 2022.
 */

#include <string.h>

#include "wheebbot_imu_can.h"

static inline uint8_t pack_left_shift_u8(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value << shift) & mask);
}

static inline uint8_t pack_left_shift_u32(
    uint32_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value << shift) & mask);
}

static inline uint8_t pack_right_shift_u32(
    uint32_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value >> shift) & mask);
}

static inline uint32_t unpack_left_shift_u32(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint32_t)((uint32_t)(value & mask) << shift);
}

static inline uint8_t unpack_right_shift_u8(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value & mask) >> shift);
}

static inline uint32_t unpack_right_shift_u32(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint32_t)((uint32_t)(value & mask) >> shift);
}

int wheebbot_imu_can_imu_heartbeat_pack(
    uint8_t *dst_p,
    const struct wheebbot_imu_can_imu_heartbeat_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u8(src_p->orient_cal_status085, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->orient_cal_status055, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->imu_temp, 0u, 0xffu);

    return (8);
}

int wheebbot_imu_can_imu_heartbeat_unpack(
    struct wheebbot_imu_can_imu_heartbeat_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->orient_cal_status085 = unpack_right_shift_u8(src_p[0], 0u, 0xffu);
    dst_p->orient_cal_status055 = unpack_right_shift_u8(src_p[1], 0u, 0xffu);
    dst_p->imu_temp = unpack_right_shift_u8(src_p[2], 0u, 0xffu);

    return (0);
}

uint8_t wheebbot_imu_can_imu_heartbeat_orient_cal_status085_encode(double value)
{
    return (uint8_t)(value);
}

double wheebbot_imu_can_imu_heartbeat_orient_cal_status085_decode(uint8_t value)
{
    return ((double)value);
}

bool wheebbot_imu_can_imu_heartbeat_orient_cal_status085_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t wheebbot_imu_can_imu_heartbeat_orient_cal_status055_encode(double value)
{
    return (uint8_t)(value);
}

double wheebbot_imu_can_imu_heartbeat_orient_cal_status055_decode(uint8_t value)
{
    return ((double)value);
}

bool wheebbot_imu_can_imu_heartbeat_orient_cal_status055_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t wheebbot_imu_can_imu_heartbeat_imu_temp_encode(double value)
{
    return (uint8_t)(value);
}

double wheebbot_imu_can_imu_heartbeat_imu_temp_decode(uint8_t value)
{
    return ((double)value);
}

bool wheebbot_imu_can_imu_heartbeat_imu_temp_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

int wheebbot_imu_can_quat_first_half_pack(
    uint8_t *dst_p,
    const struct wheebbot_imu_can_quat_first_half_t *src_p,
    size_t size)
{
    uint32_t q_i;
    uint32_t q_w;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    memcpy(&q_w, &src_p->q_w, sizeof(q_w));
    dst_p[0] |= pack_left_shift_u32(q_w, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u32(q_w, 8u, 0xffu);
    dst_p[2] |= pack_right_shift_u32(q_w, 16u, 0xffu);
    dst_p[3] |= pack_right_shift_u32(q_w, 24u, 0xffu);
    memcpy(&q_i, &src_p->q_i, sizeof(q_i));
    dst_p[4] |= pack_left_shift_u32(q_i, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u32(q_i, 8u, 0xffu);
    dst_p[6] |= pack_right_shift_u32(q_i, 16u, 0xffu);
    dst_p[7] |= pack_right_shift_u32(q_i, 24u, 0xffu);

    return (8);
}

int wheebbot_imu_can_quat_first_half_unpack(
    struct wheebbot_imu_can_quat_first_half_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint32_t q_i;
    uint32_t q_w;

    if (size < 8u) {
        return (-EINVAL);
    }

    q_w = unpack_right_shift_u32(src_p[0], 0u, 0xffu);
    q_w |= unpack_left_shift_u32(src_p[1], 8u, 0xffu);
    q_w |= unpack_left_shift_u32(src_p[2], 16u, 0xffu);
    q_w |= unpack_left_shift_u32(src_p[3], 24u, 0xffu);
    memcpy(&dst_p->q_w, &q_w, sizeof(dst_p->q_w));
    q_i = unpack_right_shift_u32(src_p[4], 0u, 0xffu);
    q_i |= unpack_left_shift_u32(src_p[5], 8u, 0xffu);
    q_i |= unpack_left_shift_u32(src_p[6], 16u, 0xffu);
    q_i |= unpack_left_shift_u32(src_p[7], 24u, 0xffu);
    memcpy(&dst_p->q_i, &q_i, sizeof(dst_p->q_i));

    return (0);
}

float wheebbot_imu_can_quat_first_half_q_w_encode(double value)
{
    return (float)(value);
}

double wheebbot_imu_can_quat_first_half_q_w_decode(float value)
{
    return ((double)value);
}

bool wheebbot_imu_can_quat_first_half_q_w_is_in_range(float value)
{
    (void)value;

    return (true);
}

float wheebbot_imu_can_quat_first_half_q_i_encode(double value)
{
    return (float)(value);
}

double wheebbot_imu_can_quat_first_half_q_i_decode(float value)
{
    return ((double)value);
}

bool wheebbot_imu_can_quat_first_half_q_i_is_in_range(float value)
{
    (void)value;

    return (true);
}

int wheebbot_imu_can_quat_second_half_pack(
    uint8_t *dst_p,
    const struct wheebbot_imu_can_quat_second_half_t *src_p,
    size_t size)
{
    uint32_t q_j;
    uint32_t q_k;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    memcpy(&q_j, &src_p->q_j, sizeof(q_j));
    dst_p[0] |= pack_left_shift_u32(q_j, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u32(q_j, 8u, 0xffu);
    dst_p[2] |= pack_right_shift_u32(q_j, 16u, 0xffu);
    dst_p[3] |= pack_right_shift_u32(q_j, 24u, 0xffu);
    memcpy(&q_k, &src_p->q_k, sizeof(q_k));
    dst_p[4] |= pack_left_shift_u32(q_k, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u32(q_k, 8u, 0xffu);
    dst_p[6] |= pack_right_shift_u32(q_k, 16u, 0xffu);
    dst_p[7] |= pack_right_shift_u32(q_k, 24u, 0xffu);

    return (8);
}

int wheebbot_imu_can_quat_second_half_unpack(
    struct wheebbot_imu_can_quat_second_half_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint32_t q_j;
    uint32_t q_k;

    if (size < 8u) {
        return (-EINVAL);
    }

    q_j = unpack_right_shift_u32(src_p[0], 0u, 0xffu);
    q_j |= unpack_left_shift_u32(src_p[1], 8u, 0xffu);
    q_j |= unpack_left_shift_u32(src_p[2], 16u, 0xffu);
    q_j |= unpack_left_shift_u32(src_p[3], 24u, 0xffu);
    memcpy(&dst_p->q_j, &q_j, sizeof(dst_p->q_j));
    q_k = unpack_right_shift_u32(src_p[4], 0u, 0xffu);
    q_k |= unpack_left_shift_u32(src_p[5], 8u, 0xffu);
    q_k |= unpack_left_shift_u32(src_p[6], 16u, 0xffu);
    q_k |= unpack_left_shift_u32(src_p[7], 24u, 0xffu);
    memcpy(&dst_p->q_k, &q_k, sizeof(dst_p->q_k));

    return (0);
}

float wheebbot_imu_can_quat_second_half_q_j_encode(double value)
{
    return (float)(value);
}

double wheebbot_imu_can_quat_second_half_q_j_decode(float value)
{
    return ((double)value);
}

bool wheebbot_imu_can_quat_second_half_q_j_is_in_range(float value)
{
    (void)value;

    return (true);
}

float wheebbot_imu_can_quat_second_half_q_k_encode(double value)
{
    return (float)(value);
}

double wheebbot_imu_can_quat_second_half_q_k_decode(float value)
{
    return ((double)value);
}

bool wheebbot_imu_can_quat_second_half_q_k_is_in_range(float value)
{
    (void)value;

    return (true);
}

int wheebbot_imu_can_euler_first_half_pack(
    uint8_t *dst_p,
    const struct wheebbot_imu_can_euler_first_half_t *src_p,
    size_t size)
{
    uint32_t euler_pitch;
    uint32_t euler_yaw;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    memcpy(&euler_yaw, &src_p->euler_yaw, sizeof(euler_yaw));
    dst_p[0] |= pack_left_shift_u32(euler_yaw, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u32(euler_yaw, 8u, 0xffu);
    dst_p[2] |= pack_right_shift_u32(euler_yaw, 16u, 0xffu);
    dst_p[3] |= pack_right_shift_u32(euler_yaw, 24u, 0xffu);
    memcpy(&euler_pitch, &src_p->euler_pitch, sizeof(euler_pitch));
    dst_p[4] |= pack_left_shift_u32(euler_pitch, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u32(euler_pitch, 8u, 0xffu);
    dst_p[6] |= pack_right_shift_u32(euler_pitch, 16u, 0xffu);
    dst_p[7] |= pack_right_shift_u32(euler_pitch, 24u, 0xffu);

    return (8);
}

int wheebbot_imu_can_euler_first_half_unpack(
    struct wheebbot_imu_can_euler_first_half_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint32_t euler_pitch;
    uint32_t euler_yaw;

    if (size < 8u) {
        return (-EINVAL);
    }

    euler_yaw = unpack_right_shift_u32(src_p[0], 0u, 0xffu);
    euler_yaw |= unpack_left_shift_u32(src_p[1], 8u, 0xffu);
    euler_yaw |= unpack_left_shift_u32(src_p[2], 16u, 0xffu);
    euler_yaw |= unpack_left_shift_u32(src_p[3], 24u, 0xffu);
    memcpy(&dst_p->euler_yaw, &euler_yaw, sizeof(dst_p->euler_yaw));
    euler_pitch = unpack_right_shift_u32(src_p[4], 0u, 0xffu);
    euler_pitch |= unpack_left_shift_u32(src_p[5], 8u, 0xffu);
    euler_pitch |= unpack_left_shift_u32(src_p[6], 16u, 0xffu);
    euler_pitch |= unpack_left_shift_u32(src_p[7], 24u, 0xffu);
    memcpy(&dst_p->euler_pitch, &euler_pitch, sizeof(dst_p->euler_pitch));

    return (0);
}

float wheebbot_imu_can_euler_first_half_euler_yaw_encode(double value)
{
    return (float)(value);
}

double wheebbot_imu_can_euler_first_half_euler_yaw_decode(float value)
{
    return ((double)value);
}

bool wheebbot_imu_can_euler_first_half_euler_yaw_is_in_range(float value)
{
    (void)value;

    return (true);
}

float wheebbot_imu_can_euler_first_half_euler_pitch_encode(double value)
{
    return (float)(value);
}

double wheebbot_imu_can_euler_first_half_euler_pitch_decode(float value)
{
    return ((double)value);
}

bool wheebbot_imu_can_euler_first_half_euler_pitch_is_in_range(float value)
{
    (void)value;

    return (true);
}

int wheebbot_imu_can_euler_second_half_pack(
    uint8_t *dst_p,
    const struct wheebbot_imu_can_euler_second_half_t *src_p,
    size_t size)
{
    uint32_t euler_roll;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    memcpy(&euler_roll, &src_p->euler_roll, sizeof(euler_roll));
    dst_p[0] |= pack_left_shift_u32(euler_roll, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u32(euler_roll, 8u, 0xffu);
    dst_p[2] |= pack_right_shift_u32(euler_roll, 16u, 0xffu);
    dst_p[3] |= pack_right_shift_u32(euler_roll, 24u, 0xffu);
    dst_p[4] |= pack_left_shift_u32(src_p->is_deg, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u32(src_p->is_deg, 8u, 0xffu);
    dst_p[6] |= pack_right_shift_u32(src_p->is_deg, 16u, 0xffu);
    dst_p[7] |= pack_right_shift_u32(src_p->is_deg, 24u, 0xffu);

    return (8);
}

int wheebbot_imu_can_euler_second_half_unpack(
    struct wheebbot_imu_can_euler_second_half_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint32_t euler_roll;

    if (size < 8u) {
        return (-EINVAL);
    }

    euler_roll = unpack_right_shift_u32(src_p[0], 0u, 0xffu);
    euler_roll |= unpack_left_shift_u32(src_p[1], 8u, 0xffu);
    euler_roll |= unpack_left_shift_u32(src_p[2], 16u, 0xffu);
    euler_roll |= unpack_left_shift_u32(src_p[3], 24u, 0xffu);
    memcpy(&dst_p->euler_roll, &euler_roll, sizeof(dst_p->euler_roll));
    dst_p->is_deg = unpack_right_shift_u32(src_p[4], 0u, 0xffu);
    dst_p->is_deg |= unpack_left_shift_u32(src_p[5], 8u, 0xffu);
    dst_p->is_deg |= unpack_left_shift_u32(src_p[6], 16u, 0xffu);
    dst_p->is_deg |= unpack_left_shift_u32(src_p[7], 24u, 0xffu);

    return (0);
}

float wheebbot_imu_can_euler_second_half_euler_roll_encode(double value)
{
    return (float)(value);
}

double wheebbot_imu_can_euler_second_half_euler_roll_decode(float value)
{
    return ((double)value);
}

bool wheebbot_imu_can_euler_second_half_euler_roll_is_in_range(float value)
{
    (void)value;

    return (true);
}

uint32_t wheebbot_imu_can_euler_second_half_is_deg_encode(double value)
{
    return (uint32_t)(value);
}

double wheebbot_imu_can_euler_second_half_is_deg_decode(uint32_t value)
{
    return ((double)value);
}

bool wheebbot_imu_can_euler_second_half_is_deg_is_in_range(uint32_t value)
{
    (void)value;

    return (true);
}

int wheebbot_imu_can_gyro_first_half_pack(
    uint8_t *dst_p,
    const struct wheebbot_imu_can_gyro_first_half_t *src_p,
    size_t size)
{
    uint32_t gyro_x;
    uint32_t gyro_y;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    memcpy(&gyro_x, &src_p->gyro_x, sizeof(gyro_x));
    dst_p[0] |= pack_left_shift_u32(gyro_x, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u32(gyro_x, 8u, 0xffu);
    dst_p[2] |= pack_right_shift_u32(gyro_x, 16u, 0xffu);
    dst_p[3] |= pack_right_shift_u32(gyro_x, 24u, 0xffu);
    memcpy(&gyro_y, &src_p->gyro_y, sizeof(gyro_y));
    dst_p[4] |= pack_left_shift_u32(gyro_y, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u32(gyro_y, 8u, 0xffu);
    dst_p[6] |= pack_right_shift_u32(gyro_y, 16u, 0xffu);
    dst_p[7] |= pack_right_shift_u32(gyro_y, 24u, 0xffu);

    return (8);
}

int wheebbot_imu_can_gyro_first_half_unpack(
    struct wheebbot_imu_can_gyro_first_half_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint32_t gyro_x;
    uint32_t gyro_y;

    if (size < 8u) {
        return (-EINVAL);
    }

    gyro_x = unpack_right_shift_u32(src_p[0], 0u, 0xffu);
    gyro_x |= unpack_left_shift_u32(src_p[1], 8u, 0xffu);
    gyro_x |= unpack_left_shift_u32(src_p[2], 16u, 0xffu);
    gyro_x |= unpack_left_shift_u32(src_p[3], 24u, 0xffu);
    memcpy(&dst_p->gyro_x, &gyro_x, sizeof(dst_p->gyro_x));
    gyro_y = unpack_right_shift_u32(src_p[4], 0u, 0xffu);
    gyro_y |= unpack_left_shift_u32(src_p[5], 8u, 0xffu);
    gyro_y |= unpack_left_shift_u32(src_p[6], 16u, 0xffu);
    gyro_y |= unpack_left_shift_u32(src_p[7], 24u, 0xffu);
    memcpy(&dst_p->gyro_y, &gyro_y, sizeof(dst_p->gyro_y));

    return (0);
}

float wheebbot_imu_can_gyro_first_half_gyro_x_encode(double value)
{
    return (float)(value);
}

double wheebbot_imu_can_gyro_first_half_gyro_x_decode(float value)
{
    return ((double)value);
}

bool wheebbot_imu_can_gyro_first_half_gyro_x_is_in_range(float value)
{
    (void)value;

    return (true);
}

float wheebbot_imu_can_gyro_first_half_gyro_y_encode(double value)
{
    return (float)(value);
}

double wheebbot_imu_can_gyro_first_half_gyro_y_decode(float value)
{
    return ((double)value);
}

bool wheebbot_imu_can_gyro_first_half_gyro_y_is_in_range(float value)
{
    (void)value;

    return (true);
}

int wheebbot_imu_can_gyro_second_half_pack(
    uint8_t *dst_p,
    const struct wheebbot_imu_can_gyro_second_half_t *src_p,
    size_t size)
{
    uint32_t gyro_z;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    memcpy(&gyro_z, &src_p->gyro_z, sizeof(gyro_z));
    dst_p[0] |= pack_left_shift_u32(gyro_z, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u32(gyro_z, 8u, 0xffu);
    dst_p[2] |= pack_right_shift_u32(gyro_z, 16u, 0xffu);
    dst_p[3] |= pack_right_shift_u32(gyro_z, 24u, 0xffu);

    return (8);
}

int wheebbot_imu_can_gyro_second_half_unpack(
    struct wheebbot_imu_can_gyro_second_half_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint32_t gyro_z;

    if (size < 8u) {
        return (-EINVAL);
    }

    gyro_z = unpack_right_shift_u32(src_p[0], 0u, 0xffu);
    gyro_z |= unpack_left_shift_u32(src_p[1], 8u, 0xffu);
    gyro_z |= unpack_left_shift_u32(src_p[2], 16u, 0xffu);
    gyro_z |= unpack_left_shift_u32(src_p[3], 24u, 0xffu);
    memcpy(&dst_p->gyro_z, &gyro_z, sizeof(dst_p->gyro_z));

    return (0);
}

float wheebbot_imu_can_gyro_second_half_gyro_z_encode(double value)
{
    return (float)(value);
}

double wheebbot_imu_can_gyro_second_half_gyro_z_decode(float value)
{
    return ((double)value);
}

bool wheebbot_imu_can_gyro_second_half_gyro_z_is_in_range(float value)
{
    (void)value;

    return (true);
}

int wheebbot_imu_can_linear_acc_first_half_pack(
    uint8_t *dst_p,
    const struct wheebbot_imu_can_linear_acc_first_half_t *src_p,
    size_t size)
{
    uint32_t x_ddot;
    uint32_t y_ddot;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    memcpy(&x_ddot, &src_p->x_ddot, sizeof(x_ddot));
    dst_p[0] |= pack_left_shift_u32(x_ddot, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u32(x_ddot, 8u, 0xffu);
    dst_p[2] |= pack_right_shift_u32(x_ddot, 16u, 0xffu);
    dst_p[3] |= pack_right_shift_u32(x_ddot, 24u, 0xffu);
    memcpy(&y_ddot, &src_p->y_ddot, sizeof(y_ddot));
    dst_p[4] |= pack_left_shift_u32(y_ddot, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u32(y_ddot, 8u, 0xffu);
    dst_p[6] |= pack_right_shift_u32(y_ddot, 16u, 0xffu);
    dst_p[7] |= pack_right_shift_u32(y_ddot, 24u, 0xffu);

    return (8);
}

int wheebbot_imu_can_linear_acc_first_half_unpack(
    struct wheebbot_imu_can_linear_acc_first_half_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint32_t x_ddot;
    uint32_t y_ddot;

    if (size < 8u) {
        return (-EINVAL);
    }

    x_ddot = unpack_right_shift_u32(src_p[0], 0u, 0xffu);
    x_ddot |= unpack_left_shift_u32(src_p[1], 8u, 0xffu);
    x_ddot |= unpack_left_shift_u32(src_p[2], 16u, 0xffu);
    x_ddot |= unpack_left_shift_u32(src_p[3], 24u, 0xffu);
    memcpy(&dst_p->x_ddot, &x_ddot, sizeof(dst_p->x_ddot));
    y_ddot = unpack_right_shift_u32(src_p[4], 0u, 0xffu);
    y_ddot |= unpack_left_shift_u32(src_p[5], 8u, 0xffu);
    y_ddot |= unpack_left_shift_u32(src_p[6], 16u, 0xffu);
    y_ddot |= unpack_left_shift_u32(src_p[7], 24u, 0xffu);
    memcpy(&dst_p->y_ddot, &y_ddot, sizeof(dst_p->y_ddot));

    return (0);
}

float wheebbot_imu_can_linear_acc_first_half_x_ddot_encode(double value)
{
    return (float)(value);
}

double wheebbot_imu_can_linear_acc_first_half_x_ddot_decode(float value)
{
    return ((double)value);
}

bool wheebbot_imu_can_linear_acc_first_half_x_ddot_is_in_range(float value)
{
    (void)value;

    return (true);
}

float wheebbot_imu_can_linear_acc_first_half_y_ddot_encode(double value)
{
    return (float)(value);
}

double wheebbot_imu_can_linear_acc_first_half_y_ddot_decode(float value)
{
    return ((double)value);
}

bool wheebbot_imu_can_linear_acc_first_half_y_ddot_is_in_range(float value)
{
    (void)value;

    return (true);
}

int wheebbot_imu_can_linear_acc_second_half_pack(
    uint8_t *dst_p,
    const struct wheebbot_imu_can_linear_acc_second_half_t *src_p,
    size_t size)
{
    uint32_t z_ddot;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    memcpy(&z_ddot, &src_p->z_ddot, sizeof(z_ddot));
    dst_p[0] |= pack_left_shift_u32(z_ddot, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u32(z_ddot, 8u, 0xffu);
    dst_p[2] |= pack_right_shift_u32(z_ddot, 16u, 0xffu);
    dst_p[3] |= pack_right_shift_u32(z_ddot, 24u, 0xffu);

    return (8);
}

int wheebbot_imu_can_linear_acc_second_half_unpack(
    struct wheebbot_imu_can_linear_acc_second_half_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint32_t z_ddot;

    if (size < 8u) {
        return (-EINVAL);
    }

    z_ddot = unpack_right_shift_u32(src_p[0], 0u, 0xffu);
    z_ddot |= unpack_left_shift_u32(src_p[1], 8u, 0xffu);
    z_ddot |= unpack_left_shift_u32(src_p[2], 16u, 0xffu);
    z_ddot |= unpack_left_shift_u32(src_p[3], 24u, 0xffu);
    memcpy(&dst_p->z_ddot, &z_ddot, sizeof(dst_p->z_ddot));

    return (0);
}

float wheebbot_imu_can_linear_acc_second_half_z_ddot_encode(double value)
{
    return (float)(value);
}

double wheebbot_imu_can_linear_acc_second_half_z_ddot_decode(float value)
{
    return ((double)value);
}

bool wheebbot_imu_can_linear_acc_second_half_z_ddot_is_in_range(float value)
{
    (void)value;

    return (true);
}

int wheebbot_imu_can_grav_first_half_pack(
    uint8_t *dst_p,
    const struct wheebbot_imu_can_grav_first_half_t *src_p,
    size_t size)
{
    uint32_t g_x;
    uint32_t g_y;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    memcpy(&g_x, &src_p->g_x, sizeof(g_x));
    dst_p[0] |= pack_left_shift_u32(g_x, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u32(g_x, 8u, 0xffu);
    dst_p[2] |= pack_right_shift_u32(g_x, 16u, 0xffu);
    dst_p[3] |= pack_right_shift_u32(g_x, 24u, 0xffu);
    memcpy(&g_y, &src_p->g_y, sizeof(g_y));
    dst_p[4] |= pack_left_shift_u32(g_y, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u32(g_y, 8u, 0xffu);
    dst_p[6] |= pack_right_shift_u32(g_y, 16u, 0xffu);
    dst_p[7] |= pack_right_shift_u32(g_y, 24u, 0xffu);

    return (8);
}

int wheebbot_imu_can_grav_first_half_unpack(
    struct wheebbot_imu_can_grav_first_half_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint32_t g_x;
    uint32_t g_y;

    if (size < 8u) {
        return (-EINVAL);
    }

    g_x = unpack_right_shift_u32(src_p[0], 0u, 0xffu);
    g_x |= unpack_left_shift_u32(src_p[1], 8u, 0xffu);
    g_x |= unpack_left_shift_u32(src_p[2], 16u, 0xffu);
    g_x |= unpack_left_shift_u32(src_p[3], 24u, 0xffu);
    memcpy(&dst_p->g_x, &g_x, sizeof(dst_p->g_x));
    g_y = unpack_right_shift_u32(src_p[4], 0u, 0xffu);
    g_y |= unpack_left_shift_u32(src_p[5], 8u, 0xffu);
    g_y |= unpack_left_shift_u32(src_p[6], 16u, 0xffu);
    g_y |= unpack_left_shift_u32(src_p[7], 24u, 0xffu);
    memcpy(&dst_p->g_y, &g_y, sizeof(dst_p->g_y));

    return (0);
}

float wheebbot_imu_can_grav_first_half_g_x_encode(double value)
{
    return (float)(value);
}

double wheebbot_imu_can_grav_first_half_g_x_decode(float value)
{
    return ((double)value);
}

bool wheebbot_imu_can_grav_first_half_g_x_is_in_range(float value)
{
    (void)value;

    return (true);
}

float wheebbot_imu_can_grav_first_half_g_y_encode(double value)
{
    return (float)(value);
}

double wheebbot_imu_can_grav_first_half_g_y_decode(float value)
{
    return ((double)value);
}

bool wheebbot_imu_can_grav_first_half_g_y_is_in_range(float value)
{
    (void)value;

    return (true);
}

int wheebbot_imu_can_grav_second_half_pack(
    uint8_t *dst_p,
    const struct wheebbot_imu_can_grav_second_half_t *src_p,
    size_t size)
{
    uint32_t g_z;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    memcpy(&g_z, &src_p->g_z, sizeof(g_z));
    dst_p[0] |= pack_left_shift_u32(g_z, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u32(g_z, 8u, 0xffu);
    dst_p[2] |= pack_right_shift_u32(g_z, 16u, 0xffu);
    dst_p[3] |= pack_right_shift_u32(g_z, 24u, 0xffu);

    return (8);
}

int wheebbot_imu_can_grav_second_half_unpack(
    struct wheebbot_imu_can_grav_second_half_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint32_t g_z;

    if (size < 8u) {
        return (-EINVAL);
    }

    g_z = unpack_right_shift_u32(src_p[0], 0u, 0xffu);
    g_z |= unpack_left_shift_u32(src_p[1], 8u, 0xffu);
    g_z |= unpack_left_shift_u32(src_p[2], 16u, 0xffu);
    g_z |= unpack_left_shift_u32(src_p[3], 24u, 0xffu);
    memcpy(&dst_p->g_z, &g_z, sizeof(dst_p->g_z));

    return (0);
}

float wheebbot_imu_can_grav_second_half_g_z_encode(double value)
{
    return (float)(value);
}

double wheebbot_imu_can_grav_second_half_g_z_decode(float value)
{
    return ((double)value);
}

bool wheebbot_imu_can_grav_second_half_g_z_is_in_range(float value)
{
    (void)value;

    return (true);
}

int wheebbot_imu_can_raw_gyro_first_half_pack(
    uint8_t *dst_p,
    const struct wheebbot_imu_can_raw_gyro_first_half_t *src_p,
    size_t size)
{
    uint32_t raw_gyro_x;
    uint32_t raw_gyro_y;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    memcpy(&raw_gyro_x, &src_p->raw_gyro_x, sizeof(raw_gyro_x));
    dst_p[0] |= pack_left_shift_u32(raw_gyro_x, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u32(raw_gyro_x, 8u, 0xffu);
    dst_p[2] |= pack_right_shift_u32(raw_gyro_x, 16u, 0xffu);
    dst_p[3] |= pack_right_shift_u32(raw_gyro_x, 24u, 0xffu);
    memcpy(&raw_gyro_y, &src_p->raw_gyro_y, sizeof(raw_gyro_y));
    dst_p[4] |= pack_left_shift_u32(raw_gyro_y, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u32(raw_gyro_y, 8u, 0xffu);
    dst_p[6] |= pack_right_shift_u32(raw_gyro_y, 16u, 0xffu);
    dst_p[7] |= pack_right_shift_u32(raw_gyro_y, 24u, 0xffu);

    return (8);
}

int wheebbot_imu_can_raw_gyro_first_half_unpack(
    struct wheebbot_imu_can_raw_gyro_first_half_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint32_t raw_gyro_x;
    uint32_t raw_gyro_y;

    if (size < 8u) {
        return (-EINVAL);
    }

    raw_gyro_x = unpack_right_shift_u32(src_p[0], 0u, 0xffu);
    raw_gyro_x |= unpack_left_shift_u32(src_p[1], 8u, 0xffu);
    raw_gyro_x |= unpack_left_shift_u32(src_p[2], 16u, 0xffu);
    raw_gyro_x |= unpack_left_shift_u32(src_p[3], 24u, 0xffu);
    memcpy(&dst_p->raw_gyro_x, &raw_gyro_x, sizeof(dst_p->raw_gyro_x));
    raw_gyro_y = unpack_right_shift_u32(src_p[4], 0u, 0xffu);
    raw_gyro_y |= unpack_left_shift_u32(src_p[5], 8u, 0xffu);
    raw_gyro_y |= unpack_left_shift_u32(src_p[6], 16u, 0xffu);
    raw_gyro_y |= unpack_left_shift_u32(src_p[7], 24u, 0xffu);
    memcpy(&dst_p->raw_gyro_y, &raw_gyro_y, sizeof(dst_p->raw_gyro_y));

    return (0);
}

float wheebbot_imu_can_raw_gyro_first_half_raw_gyro_x_encode(double value)
{
    return (float)(value);
}

double wheebbot_imu_can_raw_gyro_first_half_raw_gyro_x_decode(float value)
{
    return ((double)value);
}

bool wheebbot_imu_can_raw_gyro_first_half_raw_gyro_x_is_in_range(float value)
{
    (void)value;

    return (true);
}

float wheebbot_imu_can_raw_gyro_first_half_raw_gyro_y_encode(double value)
{
    return (float)(value);
}

double wheebbot_imu_can_raw_gyro_first_half_raw_gyro_y_decode(float value)
{
    return ((double)value);
}

bool wheebbot_imu_can_raw_gyro_first_half_raw_gyro_y_is_in_range(float value)
{
    (void)value;

    return (true);
}

int wheebbot_imu_can_raw_gyro_second_half_pack(
    uint8_t *dst_p,
    const struct wheebbot_imu_can_raw_gyro_second_half_t *src_p,
    size_t size)
{
    uint32_t raw_gyro_z;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    memcpy(&raw_gyro_z, &src_p->raw_gyro_z, sizeof(raw_gyro_z));
    dst_p[0] |= pack_left_shift_u32(raw_gyro_z, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u32(raw_gyro_z, 8u, 0xffu);
    dst_p[2] |= pack_right_shift_u32(raw_gyro_z, 16u, 0xffu);
    dst_p[3] |= pack_right_shift_u32(raw_gyro_z, 24u, 0xffu);

    return (8);
}

int wheebbot_imu_can_raw_gyro_second_half_unpack(
    struct wheebbot_imu_can_raw_gyro_second_half_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint32_t raw_gyro_z;

    if (size < 8u) {
        return (-EINVAL);
    }

    raw_gyro_z = unpack_right_shift_u32(src_p[0], 0u, 0xffu);
    raw_gyro_z |= unpack_left_shift_u32(src_p[1], 8u, 0xffu);
    raw_gyro_z |= unpack_left_shift_u32(src_p[2], 16u, 0xffu);
    raw_gyro_z |= unpack_left_shift_u32(src_p[3], 24u, 0xffu);
    memcpy(&dst_p->raw_gyro_z, &raw_gyro_z, sizeof(dst_p->raw_gyro_z));

    return (0);
}

float wheebbot_imu_can_raw_gyro_second_half_raw_gyro_z_encode(double value)
{
    return (float)(value);
}

double wheebbot_imu_can_raw_gyro_second_half_raw_gyro_z_decode(float value)
{
    return ((double)value);
}

bool wheebbot_imu_can_raw_gyro_second_half_raw_gyro_z_is_in_range(float value)
{
    (void)value;

    return (true);
}

int wheebbot_imu_can_raw_acc_first_half_pack(
    uint8_t *dst_p,
    const struct wheebbot_imu_can_raw_acc_first_half_t *src_p,
    size_t size)
{
    uint32_t raw_x_ddot;
    uint32_t raw_y_ddot;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    memcpy(&raw_x_ddot, &src_p->raw_x_ddot, sizeof(raw_x_ddot));
    dst_p[0] |= pack_left_shift_u32(raw_x_ddot, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u32(raw_x_ddot, 8u, 0xffu);
    dst_p[2] |= pack_right_shift_u32(raw_x_ddot, 16u, 0xffu);
    dst_p[3] |= pack_right_shift_u32(raw_x_ddot, 24u, 0xffu);
    memcpy(&raw_y_ddot, &src_p->raw_y_ddot, sizeof(raw_y_ddot));
    dst_p[4] |= pack_left_shift_u32(raw_y_ddot, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u32(raw_y_ddot, 8u, 0xffu);
    dst_p[6] |= pack_right_shift_u32(raw_y_ddot, 16u, 0xffu);
    dst_p[7] |= pack_right_shift_u32(raw_y_ddot, 24u, 0xffu);

    return (8);
}

int wheebbot_imu_can_raw_acc_first_half_unpack(
    struct wheebbot_imu_can_raw_acc_first_half_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint32_t raw_x_ddot;
    uint32_t raw_y_ddot;

    if (size < 8u) {
        return (-EINVAL);
    }

    raw_x_ddot = unpack_right_shift_u32(src_p[0], 0u, 0xffu);
    raw_x_ddot |= unpack_left_shift_u32(src_p[1], 8u, 0xffu);
    raw_x_ddot |= unpack_left_shift_u32(src_p[2], 16u, 0xffu);
    raw_x_ddot |= unpack_left_shift_u32(src_p[3], 24u, 0xffu);
    memcpy(&dst_p->raw_x_ddot, &raw_x_ddot, sizeof(dst_p->raw_x_ddot));
    raw_y_ddot = unpack_right_shift_u32(src_p[4], 0u, 0xffu);
    raw_y_ddot |= unpack_left_shift_u32(src_p[5], 8u, 0xffu);
    raw_y_ddot |= unpack_left_shift_u32(src_p[6], 16u, 0xffu);
    raw_y_ddot |= unpack_left_shift_u32(src_p[7], 24u, 0xffu);
    memcpy(&dst_p->raw_y_ddot, &raw_y_ddot, sizeof(dst_p->raw_y_ddot));

    return (0);
}

float wheebbot_imu_can_raw_acc_first_half_raw_x_ddot_encode(double value)
{
    return (float)(value);
}

double wheebbot_imu_can_raw_acc_first_half_raw_x_ddot_decode(float value)
{
    return ((double)value);
}

bool wheebbot_imu_can_raw_acc_first_half_raw_x_ddot_is_in_range(float value)
{
    (void)value;

    return (true);
}

float wheebbot_imu_can_raw_acc_first_half_raw_y_ddot_encode(double value)
{
    return (float)(value);
}

double wheebbot_imu_can_raw_acc_first_half_raw_y_ddot_decode(float value)
{
    return ((double)value);
}

bool wheebbot_imu_can_raw_acc_first_half_raw_y_ddot_is_in_range(float value)
{
    (void)value;

    return (true);
}

int wheebbot_imu_can_raw_acc_second_half_pack(
    uint8_t *dst_p,
    const struct wheebbot_imu_can_raw_acc_second_half_t *src_p,
    size_t size)
{
    uint32_t raw_z_ddot;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    memcpy(&raw_z_ddot, &src_p->raw_z_ddot, sizeof(raw_z_ddot));
    dst_p[0] |= pack_left_shift_u32(raw_z_ddot, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u32(raw_z_ddot, 8u, 0xffu);
    dst_p[2] |= pack_right_shift_u32(raw_z_ddot, 16u, 0xffu);
    dst_p[3] |= pack_right_shift_u32(raw_z_ddot, 24u, 0xffu);

    return (8);
}

int wheebbot_imu_can_raw_acc_second_half_unpack(
    struct wheebbot_imu_can_raw_acc_second_half_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint32_t raw_z_ddot;

    if (size < 8u) {
        return (-EINVAL);
    }

    raw_z_ddot = unpack_right_shift_u32(src_p[0], 0u, 0xffu);
    raw_z_ddot |= unpack_left_shift_u32(src_p[1], 8u, 0xffu);
    raw_z_ddot |= unpack_left_shift_u32(src_p[2], 16u, 0xffu);
    raw_z_ddot |= unpack_left_shift_u32(src_p[3], 24u, 0xffu);
    memcpy(&dst_p->raw_z_ddot, &raw_z_ddot, sizeof(dst_p->raw_z_ddot));

    return (0);
}

float wheebbot_imu_can_raw_acc_second_half_raw_z_ddot_encode(double value)
{
    return (float)(value);
}

double wheebbot_imu_can_raw_acc_second_half_raw_z_ddot_decode(float value)
{
    return ((double)value);
}

bool wheebbot_imu_can_raw_acc_second_half_raw_z_ddot_is_in_range(float value)
{
    (void)value;

    return (true);
}
