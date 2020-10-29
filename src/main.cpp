
#include <Arduino.h>
#include <Wire.h>
#include "dsps_biquad.h"

// Set LED_BUILTIN if it is not defined by Arduino framework
// #define LED_BUILTIN 2

// esp_err_t dsps_biquad_f32_ansi(const float *input, float *output, int len, float *coef, float *w);
// esp_err_t dsps_biquad_f32_ae32(const float *input, float *output, int len, float *coef, float *w);

#define BLOCK_LEN (128)
#define BQ_COEF_LEN (5)
#define BQ_STATE_LEN (2)

void setup()
{
    esp_err_t ret;
    float input[BLOCK_LEN]  = {0.0f};
    float output[BLOCK_LEN] = {0.0f};
    float coef[BQ_COEF_LEN] = {0.0f};
    float w[BQ_STATE_LEN]   = {0.0f};

    // call ansi function
    ret = dsps_biquad_f32_ansi(
        (const float *)input, output,
        BLOCK_LEN, coef, w
    );
    ret=ret;

    // call assembly function
    ret = dsps_biquad_f32_ae32(
        (const float *)input, output,
        BLOCK_LEN, coef, w
    );
    ret=ret;

}

void loop()
{

}