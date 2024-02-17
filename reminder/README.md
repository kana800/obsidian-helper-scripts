<h3 align="center">obsidian-reminder</h3>

silly little script that adds reminder on specific dates mentioned to obisidian's daily note

e
I want to add repeated events to my obsidian reminders, for example if I have pay a bill on 12th of every month. I want to showcase it on my _reminders daily note_. This is simply a solution to a _me problem_. visually, in the _reminder_ note that is generated on 12th on any month, for example reminder note on `12-01-2024` should
consist :

```md
---
title: "12-01-2024"
tags:
- daily-reminders
---
- [ ] pay mobile bill
```

I will use a simple `csv` file which consist of the list of reminders in the `date, reminder` format. I will use a [timer](https://wiki.archlinux.org/title/Systemd/Timers) that would execute a [bash script](reminder-schedule.sh) everyday. 
