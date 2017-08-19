### Intro, Notes & Section 4 Assets ###

+ Battle Tank is an open world tank fight
+ This will be a head to head battle 
+ Other player can be human or simple AI 
+ Heavy focus on control systems 
+ Also learning terrains, UI, terrain sculpting & more 
+ Dive right in and enjoy yourself!

### S04 Game Design Document (GDD) ###

+ The Concept, Rules and (initial) requirements
+ We’ll iterate around a loop while making this game 
+ Constantly asking “what’s least fun” 
+ Remember we’re not AAA studios 
+ Let’s find the essence of fun of this game.

### Setting Up a GitHub “Repo” ###

+ Creating an online repository for your project
+ GitHub provides public hosting for free 
+ We will use their default UnrealEngine **.gitignore**
+ We’ll then “clone” this repository to our machine 
+ How to use a **readme.md** with markdown*

### Creating & Deleting Landscapes ###

+ Creating an Unreal project in an existing “repo”
+ What’s good about Landscapes in Unreal Engine
+ How to add a Landscape in Unreal
+ How to delete a Landscape in Unreal.

### Landscape Setup & Scaling ###

+ You can change position & rotation later
+ Scale will impact terrain size, so set on creation 
+ How to choose your “Section Size” 
+ The effect of the “Number of Components” 
+ Creating a landscape of a specific scale.

### A Landscaping Process ###

+ **Sculpt: hills, valleys & flat areas**
+ **Smooth, flatten & ramp: create useful features**
+ **Erosion & noise: make it more organic**
+ Paint: use layered materials 
+ Details: add details (foliage, trees, etc)

### Upgrading Engine Version ###

+ Epic games launcher helps manage versions
+ Remember to commit your project first 
+ You can then “Convert in-place” 
+ Check your project runs OK in new version 
+ Close everything and re-commit 
+ How to tag a commit in GitHub.

### Using Landscape Layers ###

+ Create a material for your landscape
+ Set Usage > Used with Landscape 
+ LandscapeLayerBlend node & Vector Parameters 
+ Add at at least two layers & create LayerInfo 
+ Paint the landscape from the Modes tab 
+ Screenshot and share with us

### Flat Shading Low Poly Landscapes ###

+ Unreal’s tools are setup for photoreal landscapes 
+ Once you set the bar high, the rest must match 
+ An alternative is to opt for a low-poly look... 
+ ...then you can focus on gameplay, story, sound 
+ Can be a good choice for smaller teams 
+ How to make low-poly, flat-shaded landscapes.

### More Landscaping Tools ###

+ How to make flat shading optional
+ Importing and exporting landscape heightmaps 
+ Reducing the resolution of a landscape 
+ Using a texture in a landscape material.

### Tank Control System ###

+ Support keyboard, mouse & gamepad controller
+ Mapping player intentions to control inputs 
+ Mapping control inputs to actor actuators 
+ Introducing the concept of “fly by wire”.

### Actors from Multiple Meshes ###

+ Import the tank in 4 static mesh parts
+ Assemble the parts using sockets 
+ Create our Tank_BP and test.

### Configuring a Tank ###

+ Add mass to the tank
+ Fine-tune track position 
+ Replace root component in Tank_BP 
+ Enable physics and assign a mass 
+ Set the tank as the Default Pawn 
+ Setup PlayerStart and debug start collisions.

### 3rd Person Camera Control ###

+ Horizontal Coordinate System
+ Setup a Camera Spring Arm 
+ Why the Spring Arm alone isn’t enough 
+ How rotations don’t “commute” 
+ Binding mouse and gamepad to camera control.

### Fixing 3rd Person Camera Rotation ###

+ Use a Scene Root as azimuth gimbal
+ Use the Spring Arm for elevation control 
+ Adjust the Spring Arm length 
+ Set the camera rotation to 0 (down the arm) 
+ Decide if you want the camera to roll or not.

### User Interface (UI) in Unreal ###

+ Create a Widget Blueprint for the aim point
+ Decide the Player Controller with create the UI 
+ Create widget and add to viewport in Blueprint 
+ Override the Player Controller in the game mode.

### Main Menu Screens ###

+ Create a dedicated Scene for the Main Menu
+ Use the Level Blueprint to configure UI 
+ Add a background image to get started.

### UI Scale Box, Buttons & Mouse ###

+ Show mouse cursor in Unreal UI
+ Use a Scale Box for background image scaling
+ Add a Start button
+ Customise fonts inside our UI Widget
+ Set anchors so UI scales to different aspect ratios.

### Controller Ready Navigation ###

+ Bind Start button event to Blueprint
+ Create custom WidgetReady event
+ Make Start menu button focused on play
+ Ensure we can quit from the game
+ Aim towards Steam “Full Controller Support”.

### Trial Packaging Your Game ###

+ Creating a stand-alone game
+ Setting the first level that loads 
+ Making sure the input mode works 
+ Setting-up for “Full Controller Support”.

### Delegating to Components ###

+ How delegation can hide information
+ Creating a custom Player Controller class 
+ Re-parenting Blueprint classes onto our C++

### Using virtual and override ###

+ A virtual method can be overridden by children
+ The override keyword is a sanity check 
+ Use Super:: to include parents’ functionality 
+ Use this to add BeginPlay() to PlayerController.

### Creating an AI Controller Class ###

+ How to create a AIController based C++ class
+ Assigning an AI Controller to a Pawn 
+ Verifying which pawns are possessed 
+ Logging possession to the console.

### Get the Player Controller with C++ ###

+ Getting the AI to find the player position
+ We won’t implement line-of-sight for simplicity 
+ **UGameplayStatics::GetPlayerController()**
+ Or **GetWorld()->GetFirstPlayerController()**

### Add Tick() to PlayerController ###

+ Revise adding engine methods into new classes
+ Pseudocode our initial aiming logic 
+ Learn about Visual Assist for Visual Studio.

### Creating an Out Parameter Method ###

+ Out parameters smell a little but are used a lot
+ Allows you to return a bool and a FVector 
+ Alternative architecture would be a struct or class 
+ We’ll do it this way to get you more comfortable with creating your own methods using out parameters.

### Finding Screen Pixel Coordinates ###

+ Use FVector2D() to store pixel coordinates
+ This is two floats, pixels can be non-integer 
+ Revising UPROPERTY(EditAnywhere) and more.

### Using DeprojectScreenToWorld ###

+ How to find the camera look direction
+ What the WorldLocation parameter does
+ WorldDirection returned is a unit vector.

### Using LineTraceSingleByChannel() ###

+ We want world position of anything visible
+ GetWorld()->LineTraceSingleByChannel()
+ Use the ECC_Visibility channel for what’s seen
+ Remember HitResult is a rich object
+ Use HitResult.Location for Location member.

### Unify Player & AI Aiming ###

+ AI and Player possessed tanks aim the same way
+ Later the tank will delegate aiming 
+ But the AI/Player controllers don’t care 
+ This provides nice abstraction 
+ We also hide implementation details 
+ … and make the game more fair.

### Create Default Sub Objects in C++ ###

+ You can add required components in C++
+ Our Tank Aiming Component is a good candidate
+ We will delegate all AimAt() requests…
+ … regardless of their source (AI or player).

### BlueprintCallable() ###

+ Why StaticMeshComponet is prefixed with U
+ Creating a setter for the barrel reference 
+ How to name parameters in setters 
+ Using BlueprintCallable() to call C++ from BP 
+ Finding the start position of or projectile.

### SuggestProjectileVelocity() ###

+ How speed and velocity relate
+ The high and low projectile arc
+ Setting a launch speed on the tank
+ Introducing **SuggestProjectileVelocity()**

### Predict Projectile Landing Point ###

+ Use **SuggestProjectileVelocity()** in Unreal
+ Work out where a projectile will land.

### Using FRotators in Unreal ###

+ A FRotaor is a struct
+ It contains Roll, Pitch and Yaw as floats 
+ Convert using .Rotation() method 
+ Report aim direction as a rotator 
+ Log result to the console in Unreal.

### Using Forward Declarations ###

+ If we #include in a .h file we create a “chain”
+ Any .h file that includes us will in-turn include
+ This can be hard to keep track of
+ To simply use a type, we can “forward declare”
+ Simply put class ClassName; under the includes
+ You’ll still need to #include in the .cpp to use.

### BlueprintSpawnableComponent() ###

+ In actor blueprints you have custom components
+ Static mesh components don’t appear by default 
+ Use **BlueprintSpawnableComponent** annotation 
+ Using **hidecategories = ("CategoryName")**

### The C++ Compilation Process ###

+ More about the Unreal Header Tool (UHT)
+ Pre-processing happens first, e.g. on macros 
+ Then compilation produces .obj files 
+ These .obj files are linked by the linker 
+ How to #include strategically.

### Review Our Execution Flow ###

+ How to disable or enable tick on various classes
+ **GetWorld()->GetTimeSeconds()** for logging 
+ Documenting your execution flow for clarity 
+ Change parameter names for clarity.

### How to Report Bugs ###

+ If something’s weird break it down
+ Use logs or the debugger to follow each step 
+ SuggestProjectileVelocity() has a bug\* 
+ … it MUST have an optional parameter!? 
+ Moving to forward declarations.

### Using Clamp() to Limit Values ###

+ **FMath::Clamp\<type\>(Input, Min, Max);**
+ Very useful for restricting value ranges 
+ Clamp our Barrel’s elevation 
+ Wire it to the aiming component 
+ Test barrel elevation works.

### CHALLENGE - Turret Rotation ###

This mid-section challenge will help you integrate your knowledge and really
cement what you’ve done in the past few lectures. It will also give you a
great foundation of practical understanding on which to build. Please give it
a good shot before watching my solution.

### CHALLENGE - Turret Rotation Pt.2 ###

This is the 2nd part of the solution to this section’s longer challenge. We’ll
be finishing off the turret rotation, giving us complete barrel aiming control
by the end :-)

### Setting Up Projectiles ###

+ Create a public **Fire()** method on our tank
+ Bind input via Blueprint 
+ Call this new C++ method to test 
+ Create a **Projectile** class, and Blueprint it.

### Upgrading to Unreal 4.12 ###

+ Multiple versions of the engine take up GB
+ Upgrade Building Escape and Battle Tank 
+ Learn more about using source control 
+ Using Stash in source control 
+ Fixing issue with overlapping collision volumes.

### Working Round Awkward Bugs ###

+ About AutoWeld compound objects
+ Working through self-collision issues 
+ Disabling gravity on subobjects 
+ A reminder Unreal is designed for humanoids.

### Using SpawnActor<>() to Spawn ###

+ Using **TSubclassOf\<Type\>**
+ More about forward declarations 
+ How to use **GetWorld()->SpawnActor()**
+ How to spawn projectiles from a weapon.

### Projectile Movement Components ###

+ Recap use of **CreateDefaultSubobject()**
+ Use a **ProjectileMovementComponent**
+ Get our tank delegating launch to projectile.

### Making AI Tanks Fire ###

+ Inline some code for readability
+ Inlining can also be called “defactoring” 
+ Less lines of code is often better* 
+ * everything else being equal 
+ **FPlatformTime::Seconds()** is an accurate timer 
+ Make AI tanks fire on every frame.

### EditAnywhere vs EditDefaultsOnly ###

+ **EditAnywhere** allows all instances to be edited
+ For example each AI tank could be different 
+ **EditDefaultsOnly** allows “architype” editing 
+ In other words, all tanks must be the same 
+ Think which you want in future.

### Adding a Quit Button ###

+ Using primitive colliders in Unreal
+ Adding a quit button to our main menu.

### Setup Track Throttles ###

+ Base Tank Tracks on **UStaticMeshComponent**
+ Create a **BlueprintCallable** throttle method 
+ Bind input to track throttles 
+ Discuss what Input Axis Scale does.
