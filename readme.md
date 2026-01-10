# no-stealth-in-a-duel

bzflag plugin preventing the use of stealth in a 1v1

## funct

- forcibly drops stealth if the player count is two or less

## use

defaults to tracking stealth

```sh
-loadplugin NoStealthInADuel.so
```

can be given an explicit array of flags to track

```sh
-loadplugin NoStealthInADuel.so,ST:SW:L
```
