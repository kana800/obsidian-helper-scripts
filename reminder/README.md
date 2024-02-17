<h3 align="center">obsidian-reminder</h3>

silly little script that adds reminder on specific dates mentioned to obisidian's daily note. the program will go through a `csv` file _daily_ and if there is reminder for the _day_, it will generate a markdown file and add the _reminder_. a [timer](https://wiki.archlinux.org/title/Systemd/Timers) is used to run the script daily.

```md
---
title: "12-01-2024"
tags:
- daily-reminders
---
- [ ] pay mobile bill
```
