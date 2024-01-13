<h3 align="center">obsidian-reminder</h3>

silly little script that adds reminder on specific dates mentioned to obisidian's daily note

--- 

### problem-definition

I want to add repeated events to my obsidian reminders, for example if I have pay a bill on 12th of every month. 
I want to showcase it on my _reminders daily note_. I know that you can use a _calendar_ this is simply a solution to a 
_me problem_.

visually, in the _reminder_ note that is generated on 12th on any month, for example reminder note on `12-01-2024` should
consist :

```md
---
title: "12-01-2024"
tags:
- daily-reminders
---
- [ ] pay mobile bill
```

### "plan"

I can do this as a obisidian plugin but _nah dont wanna do it that way, need to complicate this as much as possible_. I will use a simple `csv` file.

```
date,name
12-01-2024,pay the mobile bill
```


