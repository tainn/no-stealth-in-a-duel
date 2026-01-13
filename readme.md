# no-stealth-in-a-duel

BZFlag plugin preventing the use of Stealth in a 1v1

## Funct

- forcibly drops Stealth if the player count is `<=2`

## Use

Defaults to tracking Stealth

```sh
-loadplugin NoStealthInADuel.so
```

But can be given an explicit array of flags to track

```sh
-loadplugin NoStealthInADuel.so,ST:SW:L
```
