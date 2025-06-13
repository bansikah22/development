package com.bansikah.momo_open_api_springboot_demo.client;

import com.bansikah.momo_open_api_springboot_demo.payload.AccessTokenResponse;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.*;
import org.springframework.http.MediaType;

@FeignClient(name = "momoApiAuthClient", url = "https://sandbox.momodeveloper.mtn.com/remittance")
public interface MomoApiAuthClient {

    @PostMapping(value = "/token/", consumes = MediaType.APPLICATION_JSON_VALUE)
    AccessTokenResponse getAccessToken(
            @RequestHeader("Authorization") String authorization,
            @RequestHeader("Ocp-Apim-Subscription-Key") String subscriptionKey,
            @RequestBody(required = false) String emptyJson // ensures Content-Length: 0
    );
}
