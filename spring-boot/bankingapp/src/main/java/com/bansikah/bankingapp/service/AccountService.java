package com.bansikah.bankingapp.service;

import com.bansikah.bankingapp.model.Account;
import com.bansikah.bankingapp.repository.AccountRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.Optional;

@Service
public class AccountService {

    @Autowired
    private AccountRepository accountRepository;

    public List<Account> getAllAccounts() {
        return accountRepository.findAll();
    }

    public Optional<Account> getAccountById(Long id) {
        return accountRepository.findById(id);
    }

    public Account saveAccount(Account account) {
        return accountRepository.save(account);
    }

    public Account updateAccount(Long id, Account updatedAccount) {
        return accountRepository.findById(id)
                .map(account -> {
                    account.setName(updatedAccount.getName());
                    account.setEmail(updatedAccount.getEmail());
                    account.setBalance(updatedAccount.getBalance());
                    return accountRepository.save(account);
                })
                .orElse(null);
    }

    public void deleteAccount(Long id) {
        accountRepository.deleteById(id);
    }
}