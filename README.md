# Game_Engine_2D
---
### Overview
This project is for basic game engine development algorithm.
- Engine name: Lear Engine
- Version: 1.0.0a

#### 1. Engine system
This game engine consists of several main features below

- Configuration
  - Window info - name, size, position, layer, ... by I/O file
- Editor
  - Event - handles window and input events by user input
  - Object - handles properties such as position, velocity, ...
  - Map - edit game scenes on the screen with GUI tools
- Asset (texture, animation, audio, ...)
- Input (user input)
- AI
- Physics
- Rendering 2D graphics using SDL2 based on Windows platform  

#### 2. Component
- Scenes (intro and game stages) - can add game objects
- Game object - can add texture, collider, audio
- Transform (translation, rotation, scale using 2D vectors)
- Collider (2D collision using circle and rect type)
- Audio (sound effect and music)
- Camera (third-person, top-down)

#### 3. On-board game
This engine includes a part of game source to simulate specific engine functions.

- Game name: Fly, Spider!
- Description:\
You play as a spider who has to survive in the wild such as forests or simetimes cities.\
You can shoot your cobweb to climb to destinations.
- Objects:
  - map tile
  - obstacles (like rigidbody in unity)
  - enemies (with auto moving)
- Mechanics:
  - basic physics (gravity, single pendulum, ...)
  - Environmental effects (weather - wind, rain, ...)
- Win condition:\
When a player survives and arrives at the destination
- Lose condition:\
When a player collides a negative obstacle or enemy

- Inspirations:\
This game was inspired by my friends, spiders who live in my car, especially in the side mirrors.

---
### About developer
- Name: Jake Jin
- Email: jake.jin.au@gmail.com

---
### Updates
date: 17/04/2021\
title: first commit with sources\
description:

date: 17/04/2021\
title: Git repository initialised for the game_engine_2D\
description:

---
FORMAT\
date:\
title:\
description:
