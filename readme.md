# no-stealth-in-a-duel

Prevents the use of `Stealth` in a 1v1

## Function

- Forcibly drops `Stealth` if the player count is less than or equal `2`

## Use

Defaults to tracking `Stealth`...

```sh
-loadplugin NoStealthInADuel.so
```

... but can be given an explicit array of flags to track

```sh
-loadplugin NoStealthInADuel.so,ST:SW:L
```
