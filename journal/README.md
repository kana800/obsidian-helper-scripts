<h3 align="center">journal</h3>

simple program that takes in journal entries and add them to the markdown file; at the end of the end [timer](https://wiki.archlinux.org/title/Systemd/Timers) will kick up and move journal entries to the _obsidian vault_ 

program will _create a markdown file_ when the first entry is entered; and then add the other entries according to the time.

```md
### 11:36:20
entry-1
### 12:18:10
entry-2
```

### usage

```bash
$ jrnl -e "add-entry-here"
```
