# AI Usage Disclosure

## Who you are
- **Name:** Tamjid Islam Bornil
- **NetID:** lfa37
- **Date:** 29 May, 2026
- **Link to your solution (if done via github):** *(Insert your branch or PR link here if applicable)*

---

## What you used AI for
I have used AI to brainstorm and see specific definitions, and limited my AI usage. No other usage.

---

## How you used the suggestions

### What you kept as-is:
- Conceptual definitions for structuring data relationships (such as how to organize a collection of items using standard layout rules).
- Clear, descriptive inline documentation style templates to comment on file architectures cleanly.

### What you modified and why:
- Reworked general logic definitions to fit the strict constraints of the project module structure layout (`src/services/` vs `include/`).
- Rewrote default placeholder syntax names to perfectly align with the specific variables matching the project requirements (such as `isbn`, `student_id`, and `available_count`).

### What you rejected and why:
- Rejected large blocks of monolithic function implementations or logic blocks that AI tools often generate directly inside headers or inside `main.cpp`, as this project explicitly prohibits large logic outside of the dedicated service implementation files.
- Rejected the use of global namespaces (`using namespace std;`) inside any header structures to enforce proper coding safety standards.

---

## Verification you performed

### Manual reasoning/tests you ran:
- Systematically uncommented and tested the simulation flow one discrete block at a time to trace compilation accuracy.
- Verified compiling the target modules using standard compilation tools:  
  `g++ -std=c++20 -I include main.cpp src/models/*.cpp src/services/*.cpp -o main`

### Edge cases you considered:
- Ensuring a duplicate rental transaction fails immediately if the student already holds an active copy of the exact same ISBN.
- Verifying that a student can successfully re-rent the exact same ISBN only *after* their previous active borrow record is successfully marked as completed.

### Any remaining uncertainties:
- None. The simulation executes exactly as described in the scenario workflow.

---

## Attribution
- **Tools/models used (e.g., ChatGPT/GPT-4/others):** Gemini (Google)
- **Links to prompts or session notes (if available):** N/A

---

## Additional notes (optional)

### Concerns, risks, or follow-ups:
- Focused extensively on maintaining clear responsibility separations where models strictly define what exists and services execute the actions.