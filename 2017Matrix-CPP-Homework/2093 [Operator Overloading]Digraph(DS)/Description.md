# [Operator Overloading]Digraph(DS)

### 1. ProductSet

 

* In mathematics, a Cartesian product is a mathematical operation which returns a set (or product set or simply product) from multiple sets. That is, for sets A and B, the Cartesian product A × B is the set of all ordered pairs (a, b) where a ∈ A and b ∈ B. Products can be specified using set-builder notation, e.g.

* In my file, I define it as a class. That's wrong. But I didn't find a great way to show a simple set from two sets.

* It just has two privte properties Set A and Set B.

 

 

    Remember Cartesian product is a operation.

 

### 2. Relation

 

* Relation is subset of ProductSet.

* Of cource, Relation is a operation.

* Fortunately, We can use a boolean matrix to represent a relation.

* But generally we do not discusse normal relation.

 

You need add a property named "matrix" which type is BooleanMatrix

 

### 3. Digraph

 

    If A is a finite set and R is a relation on A.

 

* I use digraph to represent first rule.

* That is, matrix will be a square matrix. And there are many properties or operations to program.

 

    1. Indegree adn Outdegree:

 

        input a number which in set.

 

        just count number from row or column way. then you can get in-degree and out-degree.

 

        if X not in set, then return -1.

 

    2. Path of length:

 

        Input a N. And calculate path. We can use a new Relation(Digraph) to represent it.

  

    3. Properties of Relations:

 

        We can identify properties of a relation by its matrix as follows.

 

        > Reflexive:

 

            ∀ (a, a) ∈ R

 

            The matrix of a reflexive relation must have all 1's on its main diagonal.

 

        > Irreflexive:

    

            ∀ (a, a) ∉ R

 

            The matrix of a irreflexive relation must have all 0's on its main diagonal.

 

        > Symmetric:

 

            (a, b) ∈ R → (b, a) ∈ R

 

            The matrix of a symmetric relation when m[ij] = 1 and m[ji] = 1.

            Or MR = MᵀR.

 

        > Asymmetric:

 

            (a, b) ∈ R → (b, a) ∉ R

 

            The matrix of an asymmetric relation when m[ij] = 1 and m[ji] = 0.

 

        > Antisymmetric:

 

            (a, b) ∈ R ∧ (b, a) ∈ R → a = b

 

            The matrix of an antisymmetric relation when i ≠ j and m[ij] = 0 or m[ji] = 0.

 

        > Tranistive:

 

            (a, b) ∈ R ∧ (b, c) ∈ R → (a, c) ∈ R

 

           The matrix of an transitive relation when m[ik] = 1 and m[kj] = 1 and m[ij] = 1.

 

Source Author: *李天培*

 