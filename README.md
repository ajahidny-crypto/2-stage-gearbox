# Gearbox

My first mechanism project: a small 2-stage gearbox designed in Fusion 360 for printing on a Bambu Lab P1S. A DC motor spins a small gear, and two gear stages slow it down 16:1, trading speed for torque. I'm a beginner, so this is mostly a log of what I tried and what I learned.

## How it works

The motor turns a small gear. That gear drives a big gear, which sits on the same shaft as a second small gear. The second small gear drives a big gear on the output shaft. Each pair is 4:1, so two pairs give 16:1.

Gears sharing a shaft turn at the same speed, which is how the reduction stacks across stages.

## The design

- 4 gears with the same tooth size (module 1.5): two with 15 teeth and two with 60
- A housing built around the gear layout
- A small 130-size DC motor and 2 mm rod for the shafts

## What I learned

- Gears that mesh need the same module (tooth size). Tooth counts can differ, and the ratio comes from that difference.
- A small gear driving a big gear lowers speed and raises torque.
- Fusion's Spur Gear add-in generates the teeth, and I still had to understand every input. It defaulted to a huge module and the wrong units, which gave me a giant gear until I caught it.
- A gear that touches two neighbors by itself is just an idler and adds no ratio. A compound gear (two gears on one shaft) is what gives a second stage.
- Meshing gears need a small gap between teeth (backlash) so printed gears don't bind.
- Rod holes should be a bit bigger than the rod, because prints come out slightly tight.
- Print at 100% scale. Scaling one gear breaks the mesh.

## What went wrong

My first plan had 6 gears and 3 stages for a much bigger ratio. The case worked out to over a foot wide, so I scrapped it. Going to 2 stages and accepting a faster output shrank everything.

My first trophy print also came out as strings and slid off the bed. After I washed the plate, adhesion was fine.

## Files

- `gearbox.f3d`: Fusion 360 file
- `/stl`: printable gears and housing
- `/images`: screenshots and photos

## Next time

I'd pick the output speed and overall size first, then work out the gears. I'd check units before generating anything and test one stage on its own before building the whole thing.

## Tools

Fusion 360, Bambu Studio, Bambu Lab P1S
