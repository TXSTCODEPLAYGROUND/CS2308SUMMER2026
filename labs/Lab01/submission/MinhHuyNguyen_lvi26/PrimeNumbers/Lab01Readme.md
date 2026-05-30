# Lab 01 — PrimeNumbers Submission Guide

This README explains **two ways to get set up** and **two ways to submit** this lab.

### Setup (two options)

- **Option A (recommended)**: Clone the entire course repo
  - Repo: `https://github.com/TXSTCODEPLAYGROUND/CS2308SPRING2026`

- **Option B (no GitHub… yet)**: Download as ZIP
  - If GitHub is not your cup-of-tea right now (we get it—you’re here to write code, not negotiate with `git`), download the repo as a ZIP, extract it, and open the `PrimeNumbers` project in CLion.

### Opening in CLion / Reloading CMake

- **If you cloned the entire repo**:
  - Open the repo with the root folder as **`CS2308SPRING2026`**
  - Navigate to this project: `labs/Lab01/PrimeNumbers`
  - Copy this project to: `labs/Lab01/submissions/yourname_netid/` (You need to create this folder)
  - Now in this new location Select `CMakeLists.txt`, right-click, then choose **Reload CMake Project**

- **If you downloaded ZIP / not using GitHub**:
  - You can open **`PrimeNumbers`** directly as the main project (often the simplest)
  - You can also reload CMake the same way using `CMakeLists.txt`

### Task

- Follow the instructions in `facts.md`.
- Navigate the code base and complete the assignment as described by the class instructions.

### Submission (two ways)

#### Option 1 — Canvas submission (ZIP)

- Zip the **entire `PrimeNumbers` folder** (with whatever solution you currently have).
  - It does **not** need to be perfect or complete at this point.
- Create and include a file named **`AIUsageDisclosure.md`** that explains how you used AI for this task.
- Submit the single ZIP file on Canvas.

#### Option 2 — GitHub submission (PR workflow)

After you complete the work, submit by pushing your lab copy into the course repo and opening a pull request.

**Starting from a clean clone**

- **Step 01: Verify you are on `main`**

```bash
git branch
```

If you are not on `main`, switch:

```bash
git switch main
```

- **Step 02: Make sure you are up-to-date**

```bash
git pull
```

- **Step 03: Make a copy of the Lab if you haven't yet**
- **Step 04: Create a folder inside `labs/Lab01/submissions/`**
  - Example: `labs/Lab01/submissions/yourname_netid`
- **Step 05: Copy the `PrimeNumbers` project into that folder**
- **Step 06: Start working on your task**
- **Step 07: Add the changes you made (be specific)**

From the repo root, you can add just your lab copy:

```bash
git add labs/Lab01/submissions/yourname_netid/PrimeNumbers
```

Or, if you are already inside the `PrimeNumbers` folder you copied, you can add changes there:

```bash
git add .
```

Or add specific files only (recommended when you’re done).

- **Step 08: Commit with a meaningful message**

```bash
git commit -m "Lab 01: Prime Numbers submitted by 'Your Name (your-netid)'"
```

- **Step 09: Create a branch and switch**
  - Branch name example format: `netid_yourname_lab01`
  - Example, `k_b459_keshavbhandari_lab01`, here `k_b459` is netid, `keshavbhandari` is my name, and `lab01` is my lab
  - Note: if you want to make changes to your lab later on please switch to this branch and keep updating it

```bash
git switch -c <new-branch-name>
```

- **Step 10: Push your branch**

```bash
git push -u origin <your-branch-name>
```

- **Step 11: Create a pull request**
  - Follow the instructions/link GitHub gives you after pushing
  - Assign these reviewers:
    - `keshavsbhandari`
    - `sandhyaneupane`

- **Step 12: Address review feedback**
  - Make updates as suggested by the reviewer(s)
  - When approved, **merge**

- **Step 13: After merging**
  - Locally, you can switch back to `main`. You may not see your work on `main` until it’s merged and pulled.
  - If you want to see your work before merging, switch back to your branch.
  - Once merged, switch to main and pull:

```bash
git switch main
git pull
```

**Final Canvas step (GitHub submitters)**:
- Once all steps are done, submit **the path to your project** in Canvas (as instructed).

