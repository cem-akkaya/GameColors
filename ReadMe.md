# Game Colors Plugin

[![Plugin version number](https://img.shields.io/github/v/release/cem-akkaya/GameColors?label=Version)](https://github.com/cem-akkaya/GameColors/releases/latest)
[![Unreal Engine Supported Versions](https://img.shields.io/badge/Unreal_Engine-5.5-9455CE?logo=unrealengine)](https://github.com/cem-akkaya/GameColors/releases)
[![License](https://img.shields.io/github/license/cem-akkaya/GameColors)](LICENSE)
[![Download count](https://img.shields.io/github/downloads/cem-akkaya/GameColors/all)](https://github.com/cem-akkaya/GameColors/releases/latest)
[![Actively Maintained](https://img.shields.io/badge/Maintenance%20Level-Actively%20Maintained-green.svg)](https://gist.github.com/cheerfulstoic/d107229326a01ff0f333a1d3476e068d)

<img src="https://cemakkaya.com/ImageHost/splashcolors.jpg" alt="plugin-game-colors" width="100%"/>


## Overview

This is an Unreal Engine plugin to organise gameplay colors and other colors efficiently during gameplay situations and feedback contexts.

Colors in game and color itself is subject of art, design, tech, science even more than that is an artificial phenomena human brain creates.
Color as well as a big source of sign of feedback for players brain. Approximately %10 of human population suffers from color blindness so that players too. In competetive games color can be crucial to gameplay or in other genres like RPG, Puzzle can be a source of fun, gameplay continuation, bells and whistles. In terms of art evoke emotions or fortify storytelling in various formats.

When it comes to game development, keeping colors consistent and organised can be hard. It can deeply effect competitiveness of gameplay or artistic look and feel. Also keeping game accessible can be a challenge and this is where "Game Colors" come in.

Solutions as color full screen color shifts and color contrast can deeply impact artistic feel of the game. Material based rendering color shifts also by design integrated in Unreal. However "Game Colors"
uses a different approach on that with profiles creating ability to change only certain colors for player, rather than all game, thus it becomes more efficient and easy to maintain by design.

This plugin is an engine subsystem with some configs where player can choose profiles defined by artists and designers, also if given option players can define their choices of profile if plugged into options.
Unlimited profiles can be added if necessary in to tables however there is four profiles already integrated as Default Profile, Deutan, Protan, Tritan, Custom.

As design pillar colors are defined in three major pillar as Beneficial (Good For Player), Natural, Non Beneficial (Bad For Player). In many games and applications we do use these colors, it is a way of lowering cognitive load for player. On the other hand, in some games there could be dynamic colors, global colors depending on the gameplay context.
When a color is defined in profile, it unlocks designer to define what color should be in different context such as tritan color blindness. Can be same or changed due to gameplay context.

Colors can be dynamically changed in system in runtime however some parts of the game could require reloading or hot reload if not created using this mindset or logic. Still there is an event integrated into subsystem that fires on color change events.
Using this event UMG events, VFX event or other changes can be done in runtime as well.

If you have any bug or crash, please open an issue in the Github repo.\
If you have suggestions, questions or need help to use you can always contact [me](https://github.com/cem-akkaya)<br>

If you want to contribute, feel free to create a pull request.

## Features

- Color organisation of multiple definitions as profile.
- Unlimited profile integration using UE standard data tables.
- Config saved and persistent.
- Event and helpers support such as hex to linear conversions.
- Single Global color independent from viewmodel or profile.
- Ability to point different data tables to settings.
- Single Dynamic color definition in each profile.
- Full accessibility solution for color blindness in games without compromise of art or functionality.

## Examples

<img src="https://cemakkaya.com/ImageHost/example5.gif" alt="Animated GIF" width="830"/>


- Multiple cubes with different color definitions from plugin changing state with color update event on hit.
- EX: Enemy is blue, you hit enemy; enemy becomes red. On Color Change-> Set Dynamic Color: Color Non Beneficial.

## Installation
<img src="https://cemakkaya.com/ImageHost/colorshowto1.jpg" alt="plugin-game-colors" width="830"/>

Install it like any other Unreal Engine plugin.
- Download and place GameColors Plugin under  : Drive:\YOURPROJECTFOLDER\Plugins\GameColors
- Activate the plugin in your project under plugins->gameplay.
- On your blueprint search for GameColor and get subsystem. Drag a pin typing color to see available functions.
- Project Settings->Plugins->GameColor to change global settings.
- Define your color profile colors for your game in the defined data table or a new table.

<img src="https://cemakkaya.com/ImageHost/colorshowto4.jpg" alt="plugin-game-colors" width="830"/>


## How to use it
<img src="https://cemakkaya.com/ImageHost/colorshowto2.jpg" alt="plugin-game-colors" width="830"/>

- On your blueprint and right click search for subsystem "Game Colors"
- Drag a pin from the subsystem and search for GameColors.
- Get AllGameColors pin and break pin.
- Get any color of your need and bind to your structure.

<img src="https://cemakkaya.com/ImageHost/colorshowto3.jpg" alt="plugin-game-colors" width="830"/>

- Drag a ping from the subsystem and assign event color change to define dynamic changes in your logic.


## FAQ
<details>
<summary><b>From Which blueprints can I access.? </b></summary>

> You can access game colors system from any blueprint including vfx.
</details>

<details>
<summary><b>Can I create additional colors on profiles? </b></summary>

> Yes, however it is hardcoded (for now) but its very easy to do if the current colors count and structure is not enough.
> In GameColorSubsystem.h->FAllGameColors define your color similar to others.
> In GameColorSubsystem.cpp->ReInitializeColors() add your color similar to others.
> Define color in your tables.

</details>

## License

This plugin is under [MIT license](LICENSE).

MIT License does allow commercial use. You can use, modify, and distribute the software in a commercial product without any restrictions.

However, you must include the original copyright notice and disclaimers.

## *Support Me*

If you like my plugin, please do support me with a coffee.

<a href="https://www.buymeacoffee.com/akkayaceq" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/default-yellow.png" alt="Buy Me A Coffee" height="41" width="174"></a>