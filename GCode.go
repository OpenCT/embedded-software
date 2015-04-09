import (
        "strconv"
        "strings"
       )

type Scanner struct {
	x, y, units, step float64
	relative          bool
}

func (context *Scanner) execute(line string) []byte {
	out := make([]byte, 2)
	tokens := strings.Split(line, " ")
	switch tokens[0] {
	case "G0":
	case "G1":
		cordinates := handleArgs(tokens[1:], "X", "Y")
		flag := 0
		if cordinates[0] != "" {
			tmp, error := strconv.ParseFloat(cordinates[0], 64)
			if error != nil {
				panic("not a number")
			}
			tmp *= context.units * context.step
			if context.relative {
				context.x += tmp
			} else {
				context.x = tmp
			}
			//checks here
			out = append(out, uint8(context.x/256), uint8(context.x))
			flag |= 1
		}
		if cordinates[1] != "" {
			tmp, error := strconv.ParseFloat(cordinates[1], 64)
			if error != nil {
				panic("not a number")
			}
			tmp *= context.step
			if context.relative {
				context.y += tmp
			} else {
				context.y = tmp
			}
			//checks here
			out = append(out, uint8(context.y/256), uint8(context.y))
			flag |= 2
		}
		out[1] = byte(flag<<4 + 1) //0yx + 0001 <- command code
		out[0] = byte(len(out) - 1)
	case "G4":
	case "G20":
		context.setIn()
		return nil
	case "G21":
		context.setMM()
		return nil
	defualt:
		panic("Invalid command")
	}
	return nil
}

func (context *Scanner) setMM() {
	context.units = 1.0
}
func (context *Scanner) setIn() {
	context.units = 2.6
}

func handleArgs(tokens []string, types ...string) []string {
	out := make([]string, len(types))
	for _, token := range tokens {
		for i, prefix := range types {
			if strings.HasPrefix(token, prefix) {
				out[i] = strings.TrimPrefix(token, prefix)
			}
		}
	}
	return out
}
