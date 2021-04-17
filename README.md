# Game_Engine_2D
---
### Overview
This project is for basic game engine development algorithm.
- Engine name: Lear Engine
- Version: 1.0.0a (updated on 17/04/2021)

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
  - Map tile
  - Obstacles (like rigidbody in unity)
  - Enemies (with auto moving)
- Mechanics:
  - Basic physics (gravity, single pendulum, ...)
  - Environmental effects (weather - wind, rain, ...)
- Win condition:\
When a player survives and arrives at the destination
- Lose condition:\
When a player collides a negative obstacle or enemy

- Inspirations:\
This game was inspired by my friends, spiders who live in my car, especially in the side mirrors.
#### 4. UML Class Diagram

#### 5. Milestone
date: 17/04/2021
| Task | Start | End | Progress(%) |
| --- | --- | --- | :---: |
| Preparation |
| - Study C++17 | | 18/04/2021 | 100 |
| - Study Win32 | | 18/04/2021 | 70 |
| - Study Git | | 18/04/2021 | 100 |
| - Design game engine | | 18/04/2021 | 100 |
| - Build initial game engine | | 18/04/2021 | 80 |
| Development - Objects |
| - Get game resources | 19/04/2021 | 20/04/2021 | |
| - Design game maps | 20/04/2021 | 20/04/2021 | |
| - Construct game maps | 21/04/2021 | 21/04/2021 | |
| - Construct game objects | 22/04/2021 | 22/04/2022 | |
| - Deploy game objects | 23/04/2021 | 23/04/2021 | |
| Development - Physics |
| - Develop physical movement - gravity | 24/04/2021 | 24/04/2021 | |
| - Develop physical movement - single pendulum | 24/04/2021 | 25/04/2021 | |
| Development - Animation |
| - Animate framed textures | 24/04/2021 | 25/04/2021 | |
| - Animate textures using physics | 24/04/2021 | 25/04/2021 | |
| Test & Update | 26/04/2021 | | |

---
### About developer
- Name: Jake Jin
- Email: jake.jin.au@gmail.com

---
### Updates
date: 17/04/2021\
version: 1.0.0a\
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
