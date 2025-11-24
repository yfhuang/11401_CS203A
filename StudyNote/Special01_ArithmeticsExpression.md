# Special Topic: Arithmetic Expressions with Stacks and Trees

## 1. What is an arithmetic expression?

### 1.1 Informal definition

An **arithmetic expression** is a combination of:

* **Operands**

  * constants (e.g., `3`, `10`, `2.5`)
  * variables (e.g., `x`, `y`, `total`)
* **Operators**

  * binary: `+`, `-`, `*`, `/`, `%`, `^`, …
  * unary: `-x`, `+x` (unary plus/minus), function calls `sin(x)`, `max(a, b)`
* **Parentheses** `(` `)`

  * override default order of evaluation
  * control grouping: `(3 + 5) * 2` vs. `3 + (5 * 2)`

Expression examples:

* `3 + 5`
* `(3 + 5) * (2 - 4)`
* `-a + f(b, c*d)`

### 1.2 Precedence and associativity

To interpret expressions consistently:

* **Precedence** (typical):

  * Highest: unary operators, function calls
  * Then: `*`, `/`, `%`
  * Then: `+`, `-`
* **Associativity**:

  * Many binary ops are **left-associative**:
    `a - b - c` = `(a - b) - c`
  * Some are **right-associative** (e.g., exponentiation in some languages):
    `a ^ b ^ c` = `a ^ (b ^ c)`

> Key idea: an arithmetic expression is **not just a string of characters**; it has an **implicit structure** that determines how it should be evaluated.

---

## 2. Representations of an arithmetic expression (and what they mean)

Take this example:

```text
(3 + 5) * (2 - 4)
```

We can represent it in several ways:

### 2.1 As a raw string

Exactly what a human writes:

```text
"(3 + 5) * (2 - 4)"
```

* Easy for humans to read
* Ambiguous for a machine without parsing

### 2.2 As a token sequence

The compiler or interpreter typically tokenizes:

```text
"(" "3" "+" "5" ")" "*" "(" "2" "-" "4" ")"
```

becomes something like:

```text
LPAREN, NUM(3), PLUS, NUM(5), RPAREN, TIMES, LPAREN, NUM(2), MINUS, NUM(4), RPAREN
```

### 2.3 As an **expression tree** (structural representation)

Build a tree that encodes the structure:

```text
           *
         /   \
       +       -
      / \     / \
     3   5   2   4
```

* Internal nodes: **operators** (`*`, `+`, `-`)
* Leaves: **operands** (`3`, `5`, `2`, `4`)

No parentheses needed in the tree: the structure itself defines order.

### 2.4 As a numeric value

If we evaluate:

```text
(3 + 5) * (2 - 4) = 8 * (-2) = -16
```

The final **value** is another “representation” of the expression’s meaning.

> Summary: An expression has **multiple faces** – string, tokens, tree, value – and we use different data structures to move between them (stack, tree).

---

## 3. Prefix, Infix, Postfix: three notations, one tree

### 3.1 Notations and their meanings

Given the same expression `(3 + 5) * (2 - 4)`, we can write:

* **Infix** (common human form):

  ```text
  (3 + 5) * (2 - 4)
  ```
* **Prefix** (Polish notation): operator first

  ```text
  * + 3 5 - 2 4
  ```
* **Postfix** (Reverse Polish notation): operator last

  ```text
  3 5 + 2 4 - *
  ```

### 3.2 Tree traversals and notations

For the expression tree:

```text
           *
         /   \
       +       -
      / \     / \
     3   5   2   4
```

Use the standard depth-first traversals:

| Traversal | Visit order         | Result for this tree | Notation |
| --------- | ------------------- | -------------------- | -------- |
| Preorder  | Root → Left → Right | `* + 3 5 - 2 4`      | Prefix   |
| Inorder   | Left → Root → Right | `(3 + 5) * (2 - 4)`  | Infix    |
| Postorder | Left → Right → Root | `3 5 + 2 4 - *`      | Postfix  |

So we have a **direct equivalence**:

* **Prefix** ↔ **Preorder traversal**
* **Infix** ↔ **Inorder traversal**
* **Postfix** ↔ **Postorder traversal**

### 3.3 Why prefix and postfix do not need parentheses

For expressions where every operator has a fixed number of operands (e.g., binary operators only):

* In **prefix**, when you read an operator, you know the next tokens belong to its operands.
* In **postfix**, when you read an operator, you know the preceding tokens provided its operands.

Because of this, the **structure can be reconstructed unambiguously**:

* Either by parsing (prefix from left to right, postfix from left to right with a stack)
* Or by building a tree

So **no parentheses are needed** in prefix or postfix, as long as operator arity is known.

---

## 4. Stack and Tree: why both can handle arithmetic expressions

Now we connect the two data structures.

### 4.1 Stack-based view (linear, algorithmic)

The stack processes expressions **as a sequence of tokens**, especially postfix (and prefix with some changes).

**Postfix evaluation (classic algorithm):**

For `3 5 + 2 4 - *`:

1. Scan left to right.
2. If the token is an operand → **push** it.
3. If the token is an operator → **pop** required operands, apply the operator, **push** the result.
4. At the end, one value remains: the result.

This is simple, linear, and stack-friendly.

### 4.2 Tree-based view (structural, hierarchical)

The expression tree evaluation uses recursion:

```c
int eval(Node* root) {
    if (root is a leaf) return root->value;
    int left_val = eval(root->left);
    int right_val = eval(root->right);
    return apply(root->op, left_val, right_val);
}
```

This is essentially a **postorder** evaluation:

* Evaluate left subtree
* Evaluate right subtree
* Apply operator at the parent

Conceptually, this is doing the same thing as postfix evaluation, but **navigating the tree** instead of a linear token list.

### 4.3 What do Stack and Tree have in common?

* Both are used to handle **nested subexpressions**.
* Both rely on the idea that **inner expressions must finish before outer expressions**.

Underlying mechanism:

* Recursive evaluation of the tree uses the **call stack** (implicit stack).
* Postfix evaluation uses an **explicit stack**.

So you can say:

> * Postorder traversal of the expression tree → **postfix**.
> * Evaluating the tree recursively → equivalent to evaluating postfix with a stack.
> * The stack is like a linear “simulation” of the tree’s nested structure.

### 4.4 Algorithms that connect all representations

This is the powerful part of the section: moving between **string, stack, and tree**.

#### 4.4.1 Infix → Postfix (stack algorithm / Shunting Yard idea)

Goal: convert human-friendly infix into stack-friendly postfix.

High-level algorithm (binary operators and parentheses):

1. Initialize an empty **operator stack** and an empty **output list**.
2. Scan the infix tokens from left to right:

   * If token is an **operand** → append to output.
   * If token is an **operator**:

     * While top of the stack has an operator with **greater or equal precedence** (and is not `(`),
       pop it and append to output.
     * Push the current operator on the stack.
   * If token is `(` → push it onto stack.
   * If token is `)` → pop and append until `(` is on top; pop and discard the `(`.
3. After all tokens are read, pop and append **all remaining operators**.

Example:

Infix: `A + B * C`

* Output: `A B C * +` (postfix)

#### 4.4.2 Postfix → Expression Tree (stack of nodes)

Goal: build the **expression tree** so we can visualize and traverse.

Algorithm:

1. Initialize an empty stack of **tree nodes**.
2. Scan postfix tokens from left to right:

   * If operand `x`:

     * Create a node `N` with value `x`, no children.
     * Push `N` onto the stack.
   * If operator `op` (binary):

     * Pop node `right`
     * Pop node `left`
     * Create node `N` with operator `op`, left child = `left`, right child = `right`
     * Push `N` onto the stack.
3. At the end, the stack has exactly one node — the **root** of the expression tree.

This algorithm shows **stack building the tree**.

#### 4.4.3 Expression Tree → Prefix / Infix / Postfix (traversal)

Once the tree is built, we can generate each notation via traversal:

* Preorder → Prefix
* Inorder → Infix
* Postorder → Postfix

This is the **tree producing the linear expressions**.

#### 4.4.4 Postfix / Tree → Final result

From here, two evaluation paths:

* Path A: evaluate postfix with a stack (explicit).
* Path B: recursively evaluate the tree (implicit stack).

Both will give the same numeric result.

---

## 5. Big picture: layout of the special section

This is how I’d present it to students as a “mini unit”:

---

### 5.1 Part 1 – Definition of arithmetic expressions

* What is an expression?
* Operands, operators, parentheses
* Precedence and associativity

### 5.2 Part 2 – Representations and meanings

* String form (what we type)
* Tokens (what the parser reads)
* Expression tree (what the structure looks like)
* Numeric value (what it evaluates to)

### 5.3 Part 3 – Prefix / Infix / Postfix and tree traversals

* Definition of each notation
* Same tree, three different traversal outputs
* Prefix ↔ Preorder / Infix ↔ Inorder / Postfix ↔ Postorder
* Why prefix/postfix don’t need parentheses

### 5.4 Part 4 – Stack and Tree: how they both apply

1. **Stack:**

   * Evaluate postfix using push/pop
   * Infix → Postfix conversion (stack-based)

2. **Tree:**

   * Postfix → Expression tree (stack of nodes)
   * Traversals produce Prefix/Infix/Postfix
   * Recursive tree evaluation (postorder)

3. **Common core:**

   * Both handle nested subexpressions using LIFO logic (explicit or implicit stack)
   * Tree = **structural view**, Stack = **algorithmic/operational view**

### 5.5 Part 5 – Extended note (for advanced students)

* Expression trees are a part of the **Abstract Syntax Tree (AST)** in compilers.
* AST nodes can represent:

  * Binary operators (`+`, `-`, `*`, `/`)
  * Unary operators (`-x`)
  * Function calls (`f(x, y)`)
* Many optimizations and code generation steps operate on these trees.
