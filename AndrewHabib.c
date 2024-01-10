#include <stdio.h>
#include <string.h>

int right_len(char pass[]) {
	if (strlen(pass) >= 8) {
		return 1;
	}
	printf("\nError: Password should be at least 8 characters long.\n");
	printf("Re-enter a longer password.\n");
	return 0;	
}

int hasLowercase(char pass[]) {
	int i;
	for (i = 0; pass[i] != '\0'; i++) {
		if (pass[i] >= 'a' && pass[i] <= 'z') {
			return 1;
		}
	}
	return 0;
}

int hasUppercase(char pass[]) {
	int i;
	for (i = 0; pass[i] != '\0'; i++) {
		if (pass[i] >= 'A' && pass[i] <= 'Z') {
			return 1;
		}
	}
	return 0;

}

int hasDigit(char pass[]) {
	int i;
	for (i = 0; pass[i] != '\0'; i++) {
		if (pass[i] >= '0' && pass[i] <= '9') {
			return 1;
		}
	}
	return 0;
}

int hasSpecialChar(char pass[]) {
 	int i;
	for (i = 0; pass[i] != '\0'; i++) {
		if (pass[i] == '!' || pass[i] == '@' || pass[i] == '#' || pass[i] == '$' || pass[i] == '%' || pass[i] == '^' || pass[i] == '&' || pass[i] == '*' || pass[i] == '(' || pass[i] == ')') {
			return 1;
		}
	}
	return 0;
}

int evaluateStrength(char pass[]) {
	int score = 0;
	if (hasLowercase(pass)) {
		score = score + 1;
	} 
	if (hasUppercase(pass)) {
		score = score + 1;
	} 
	if (hasDigit(pass)) {
		score = score + 1;
	} 
	if (hasSpecialChar(pass)) {
		score = score + 1;
	} 
	if (strlen(pass) >= 12) {
		score = score + 1;
	} 
	return score;
}

void output(int strength, int choice) {
	char display_strength[10];
	if (strength >= 0 && strength <= 2) {
		strcpy(display_strength, "Weak");
	} else if (strength == 3 || strength == 4) {
		strcpy(display_strength, "Moderate");
	} else if (strength == 5) {
		strcpy(display_strength, "Strong");
	}

	if (choice == 1) {
		printf("Password Strength: %s\n", display_strength);
	} else if (choice == 2) {
		printf("Last tested password: %s\n", display_strength);
	}
}

int main() {
	char pass[200] = "";
	int choice;
	while (1) {
		printf("\nPassword Resilience Analyzer\n");
		printf("1. Test a new password\n");
		printf("2. View strength of the last tested password\n");
		printf("3. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		if (choice == 1) {
			while (1) {
				printf("Enter the password: ");
				scanf("%s", &pass);
				if (right_len(pass) == 1) {
					break;
				}
			}
			output(evaluateStrength(pass), choice);
		} else if (choice == 2) {
			if (strlen(pass) == 0) {
				printf("No password has been entered previously!\n");
			} else {
				output(evaluateStrength(pass), choice);
			}
		} else if (choice == 3) {
			printf("Exiting...\n");
			break;
		} else {
			printf("Invalid choice!\n");
			break;
		}
	}
	return 0;
}

