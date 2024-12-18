
package com.basikah.spring_boot_hpa.controller;


import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class LoadController {

    @GetMapping("/cpu")
    public String simulateCpuLoad() {
        long startTime = System.currentTimeMillis();
        while (System.currentTimeMillis() - startTime < 5000) {
            // Simulating CPU-intensive task
            Math.random();
        }
        return "CPU Load simulated!";
    }
}
