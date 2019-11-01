'use strict';

function stepsToSolveHanoiT(height, srcP, desP, bufferP) {
  if (height >= 1) {

    // Move a tower of height-1 to the buffer peg, using the destination peg.
    stepsToSolveHanoiT(height - 1, srcP, bufferP, desP);

    // Move the remaining disk to the destination peg.
    console.log('Move disk from Tower ', srcP, ' to Tower ', desP);

    // Move the tower of `height-1` from the `buffer peg` to the `destination peg` using the `source peg`.        
    stepsToSolveHanoiT(height - 1, bufferP, desP, srcP);
  }
  
  return;
}

stepsToSolveHanoiT(3, "A", "C", "B");