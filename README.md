# Air-puff-task
Air puff stimuli delivery atomatization with arduino and Bonsai software
These proyect was created for a behavioral assesment of sensory perception in a mouse model of ASD.
These program is design to be used with two arduinos, one in charge of paw detection through bonsai ephys software
and the second one in charge of the onset/offset of the TTL signal that delivers the stimuli.

The first arduino needs to have loaded the standar firmata protocol.

There are different versions of the porotocol for the second arudino:
1. bonsai signal: the basic one, every time the paw is detected the TTL signal is se to (OFF) wich triggers the delivery of the stimuli.
2. bonsai-signal-newstim: the same as before but the state of the TTL singnal is (ON) for stimuli delivery.
3. air-puff-every-10s: delivers a stimuli every 10 seconds, doesnt need paw detection. (OFF)
4. air-puff-every-10s-newstim: delivers a stimuli every 10 seconds, doesnt need paw detection. (ON)
5. air-puff-opto: works as bonsai signal, just add a second TTL signal to trigger optogenetic stimulation.
4. 
