case class FibHeap[T <: Ordered[T]]
(
    // Root won't have a value, all other nodes will
    value: Option[T],
    kids: IndexedSeq[FibHeap[T]],
    numNodes: Int,
    isMarked: Boolean,
    minKidIndex: Int
) {
    // Root won't have a value, all other nodes will
    def findMin(): T = value.getOrElse(kids(minKidIndex).value.get)

    def merge(other: FibHeap[T]): FibHeap[T] = {
        if (this.findMin() < other.findMin()) {
            this.copy(
                kids = this.kids :+ other,
                numNodes = this.numNodes + other.numNodes,
            )
        }
        else {
            other.copy(
                kids = other.kids :+ this,
                numNodes = this.numNodes + other.numNodes,
            )
        }
    }

    def insert(t: T): FibHeap[T] = {
        this.merge(
            FibHeap(
                Some(t),
                IndexedSeq(),
                1,
                false,
                -1
            )
        )
    }

    // Should only be called on the root
    def extractMin(): (T, FibHeap[T]) = {
        val minEl = kids.minBy((f: FibHeap[T]) => f.findMin())
        val remainingKids = kids.diff(IndexedSeq(minEl))

        def makeUnique(items: IndexedSeq[FibHeap[T]], acc: IndexedSeq[FibHeap[T]]): IndexedSeq[FibHeap[T]] = {
            items match {
                case IndexedSeq() => acc
                case el +: rest =>
                    acc.find(a => a.numNodes == el.numNodes) match {
                        case None => makeUnique(rest, acc :+ el)
                        case Some(other) => makeUnique(rest :+ el.merge(other), acc.diff(IndexedSeq(other)))
                    }
            }
        }
        val newTrees = makeUnique(minEl.kids ++ remainingKids, IndexedSeq())
        val newMinEl = newTrees.minBy((f: FibHeap[T]) => f.findMin())
        val newHeap = FibHeap(
            None,
            newTrees,
            newTrees.map(_.numNodes).sum,
            false,
            newTrees.indexWhere(_ == newMinEl)
        )
        (minEl.value.get, newHeap)
    }
}
