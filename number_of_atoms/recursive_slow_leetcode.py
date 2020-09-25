class Solution:
    def countOfAtoms(self, formula: str) -> str:
        def cummulate_atoms(formula):
            atoms = {}
            i = 0
            while i < len(formula):
                if (formula[i] == "("):
                    # find index of matching ")"
                    m_paran = formula.rfind(")")
                    atoms_rec = cummulate_atoms(formula[i+1:m_paran])

                    # Figure out the multiplier of the paranthesis if any
                    multiplier = "1"

                    # If there is a digit after paranthesis
                    num_of_digits = 0
                    if formula[m_paran+1].isdigit():
                        num_of_digits = 1
                        # If it has more digits than one
                        if m_paran+2 < len(formula):
                            while formula[m_paran+1+num_of_digits].isdigit():
                                num_of_digits += 1
                                if m_paran+1+num_of_digits >= len(formula):
                                    break
                        multiplier = formula[m_paran+1:m_paran+1+num_of_digits]
                    
                    multiplier = int(multiplier)

                    # Now, fuse the two atom dictionaries
                    for key in atoms_rec:
                        if (key in atoms):
                            atoms[key] += atoms_rec[key] * multiplier
                        else:
                            atoms[key] = atoms_rec[key] * multiplier

                    # Now figure out where to skip to.
                    i = m_paran + num_of_digits
                    next
                tla = 0 # two letter atom status
                if (formula[i].isalpha() and formula[i].isupper()):
                    if i+1 < len(formula):
                        if (formula[i+1].isalpha() and formula[i+1].islower()):
                            tla = 1
                    if (formula[i:i+1+tla] in atoms):
                        atoms[formula[i:i+1+tla]] = atoms[formula[i:i+1+tla]] + 1
                    else:
                        atoms[formula[i:i+1+tla]] = 1
                    #print(atoms)
                    # if there's a digit, after the letter, we need to add it to the value (minus one)
                    if i+1+tla < len(formula):
                        if (formula[i+1+tla].isdigit()):
                            num_of_digits = 1
                            if i+2+tla < len(formula):
                                while formula[i+1+num_of_digits+tla].isdigit():
                                    num_of_digits += 1
                                    if i+2+num_of_digits+tla >= len(formula):
                                        break
                            atoms[formula[i:i+1+tla]] = atoms[formula[i:i+1+tla]] - 1 + int(formula[i+1+tla:i+1+num_of_digits+tla:1])
                            i = i + num_of_digits
                            next
                i += 1
                next
            return atoms
        return ''.join(x if y == 1 else x+str(y) for x, y in sorted(cummulate_atoms(formula).items()))