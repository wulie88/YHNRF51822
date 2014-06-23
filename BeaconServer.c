typedef __packed struct
{
    uint16_t unknown1;
    uint8_t uuid[16];
    uint16_t major;
    uint16_t minor;
    uint8_t unknown2;
} clbeacon_info_t;

static void advertising_init(void)
{
    uint32_t      err_code;
    uint8_t       flags = BLE_GAP_ADV_FLAG_BR_EDR_NOT_SUPPORTED;
    ble_advdata_t advdata;

    uint8_t uuid[16] = {0x01, 0x12, 0x23, 0x34, 0x45, 0x56, 0x67, 0x78, 0x89, 0x9a, 0xab, 0xbc, 0xcd, 0xde, 0xef, 0xf0};

    clbeacon_info_t beacon_info;
    beacon_info.unknown1 = 0x1502;
    memcpy(&beacon_info.uuid, &uuid, sizeof(uuid));
    beacon_info.major = 0x3412;
    beacon_info.minor = 0x7798;
    beacon_info.unknown2 = 0xC5;

    ble_advdata_manuf_data_t manuf_specific_data;
    manuf_specific_data.company_identifier = 0x004C;
    manuf_specific_data.data.p_data        = (uint8_t *) &beacon_info;
    manuf_specific_data.data.size          = sizeof(beacon_info);

    // Build and set advertising data
    memset(&advdata, 0, sizeof(advdata));

    advdata.name_type               = BLE_ADVDATA_NO_NAME;
    advdata.flags.size              = sizeof(flags);
    advdata.flags.p_data            = &flags;
    advdata.p_manuf_specific_data   = &manuf_specific_data;

    err_code = ble_advdata_set(&advdata, NULL);
    APP_ERROR_CHECK(err_code);
}


/**@brief Start advertising.
 */
static void advertising_start(void)
{
    uint32_t             err_code;
    ble_gap_adv_params_t adv_params;

    // Start advertising
    memset(&adv_params, 0, sizeof(adv_params));

    adv_params.type        = BLE_GAP_ADV_TYPE_ADV_NONCONN_IND;
    adv_params.p_peer_addr = NULL;
    adv_params.fp          = BLE_GAP_ADV_FP_ANY;
    adv_params.interval    = APP_ADV_INTERVAL;
    adv_params.timeout     = APP_ADV_TIMEOUT_IN_SECONDS;

    err_code = sd_ble_gap_adv_start(&adv_params);
    APP_ERROR_CHECK(err_code);
    nrf_gpio_pin_set(ADVERTISING_LED_PIN_NO);
}
