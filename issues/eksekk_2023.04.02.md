**Major**

- [???] Couldn't run x64 build (on 64-bit windows), x32 worked fine without any changes other than running cmake config for 32-bit and selecting "run" in visual studio
- [??? Does it related to OpenEnroth#294?] sometimes spells "fly through" enemies without doing damage (mostly when they are close), and very rarely don't target an enemy that is clearly in front of party (I saw this in temple of the moon with rats and casting firebolt)
 
**Minor**

- [Fixed with OpenEnroth#627] When cycling through characters during party creation, "choose me" lines don't stop playing when you choose other char
- [New issue: OpenEnroth#624] idk how it is in vanilla, but holding down "backspace" to erase file name during saving doesn't work, it should the above is a problem with all keys, including spacebar (which is shown in video)
- [???] emerald island healer's wells restore hp/sp even when it is full
- [New issue: OpenEnroth#642] I sometimes got "nobody is in condition..." message when looting enemies, apparently it's caused by trying to loot flying enemies, when corpse is in air (didn't reach ground yet) EDIT: happens even with nonflying enemies, for example temple of the moon spiders
- [New issue: OpenEnroth#626] selection of save (when loading or saving) was retained in vanilla between different openings of menu (even across new games), while in OE first save is selected every time
- [???] I had a weird situation where when looting temple of the moon spider's chest, additional chain armor appeared upon picking up gold pile (first item picked), can't replicate it after loading save
- [???] Sal Sharktooth in TotM doesn't get hostile when refusing to give hat, only green swordsman does (possible it's vanilla bug)
- [??? Vanilla always play 4 movies] when launching the game, all four movies always play, while in vanilla that was only on first launch, after only lore/sci-fi introductory one played there seems to be some issue with timers.
- [???] In vanilla, when you clicked emerald island gold well (and had enough luck) below 1k gold, you got 1k gold. If some time passed (for example training) and you got below 1k and clicked again, you'd get another 1k gold. This way you could get gold from well 3 times. In OE, only first time works.
 
**Minor minor**

- [New issue: OpenEnroth#631] Skill names during party creation are not centered
- [New issue: OpenEnroth#625] all characters get club at the start, in vanilla it was like that only in mm6
- [Vanilla bug, plus it is in LOD not executable] emerald island anvil is labelled "button"
- [New issue: OpenEnroth#622] no sound when clicking "stats", "skills" etc. in character screen, and "save game" confirm
- [New issue: OpenEnroth#643] there is no icon for exe file :/
- [New issue: OpenEnroth#644] when a character is dead (can't act) and you try to select him with keyboard nothing happens, in vanilla selection cycled among conscious characters
- [Issue already exist: OpenEnroth#581] when healing in house by pressing 1, then heal, then 2 and heal etc. as fast as possible, "gold paid" sound is not always played, same happens with gold piles in chests
- [Not confirmed, in vanilla also take 50 gold for dead characters] I vaguely recall (may be wrong) that emerald island healer wanted 10 gold even for curing death (now it's 50)
- [New issue: OpenEnroth#623] "stat increased" sound in addition to gold sound is played when learning skill in shops (in vanilla only gold sound played)
- [Not confirmed, vanilla have just peasant there] on emerald island, there is no hireable npc on boat (in vanilla there is one)
