package com.bansikah.momo_open_api_springboot_demo.client;

import com.bansikah.momo_open_api_springboot_demo.dto.AccountBalanceDto;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestHeader;

@FeignClient(name = "momoApiClient", url = "${mtn.momo.base-url}")
public interface MomoApiClient {

    @GetMapping("/remittance/v1_0/account/balance")
    AccountBalanceDto getAccountBalance(
            @RequestHeader("Authorization") String bearerToken,
            @RequestHeader("X-Target-Environment") String targetEnvironment,
            @RequestHeader("Ocp-Apim-Subscription-Key") String subscriptionKey
    );
}
