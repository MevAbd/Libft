#include "../libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

static int passed = 0, failed = 0;

void test(const char *name, int result) {
	if (result) { printf("%s✓%s %s\n", GREEN, RESET, name); passed++; }
	else { printf("%s✗%s %s\n", RED, RESET, name); failed++; }
}

void section(const char *name) {
	printf("\n%s─── %s ───%s\n", YELLOW, name, RESET);
}

char toupper_mapi(unsigned int i, char c) {
	(void)i;
	return (c >= 'a' && c <= 'z') ? c - 32 : c;
}

char identity_mapi(unsigned int i, char c) {
	(void)i;
	return c;
}

void to_upper_iteri(unsigned int i, char *c) {
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

void *map_func(void *content) {
	return ft_strdup((char *)content);
}

void print_content(void *content) {
	(void)content;
}

int main(void) {
	printf("\n%s═══════════════════════════════════════════════════════════════%s\n", "\033[1m", RESET);
	printf("%s                    TEST COMPLET LIBFT%s\n", "\033[1m", RESET);
	printf("%s═══════════════════════════════════════════════════════════════%s\n\n", "\033[1m", RESET);
	
	// ========== STRLEN ==========
	section("ft_strlen");
	test("ft_strlen: chaîne normale", ft_strlen("hello") == 5);
	test("ft_strlen: chaîne vide", ft_strlen("") == 0);
	test("ft_strlen: chaîne longue", ft_strlen("abcdefghijklmnopqrstuvwxyz") == 26);
	test("ft_strlen: un caractère", ft_strlen("a") == 1);
	
	// ========== MEMSET ==========
	section("ft_memset");
	char buf1[20];
	ft_memset(buf1, 'A', 10);
	test("ft_memset: remplissage basique", buf1[0] == 'A' && buf1[9] == 'A' && buf1[10] != 'A');
	ft_memset(buf1, 0, 20);
	test("ft_memset: remplissage avec 0", buf1[0] == 0 && buf1[19] == 0);
	ft_memset(buf1, 'Z', 1);
	test("ft_memset: taille 1", buf1[0] == 'Z' && buf1[1] == 0);
	char buf1b[20] = {0};
	ft_memset(buf1b, 'X', 0);
	test("ft_memset: taille 0", buf1b[0] == 0);
	ft_memset(buf1b, 255, 5);
	test("ft_memset: valeur 255", buf1b[0] == (char)255 && buf1b[4] == (char)255);
	ft_memset(buf1b, -1, 3);
	test("ft_memset: valeur négative", buf1b[0] == (char)-1);
	
	// ========== BZERO ==========
	section("ft_bzero");
	char buf2[10] = "test";
	ft_bzero(buf2, 4);
	test("ft_bzero: mise à zéro", buf2[0] == 0 && buf2[3] == 0);
	char buf2b[10] = "abcdefgh";
	ft_bzero(buf2b, 0);
	test("ft_bzero: taille 0", buf2b[0] == 'a');
	char buf2c[10] = "test";
	ft_bzero(buf2c, 1);
	test("ft_bzero: taille 1", buf2c[0] == 0 && buf2c[1] == 'e');
	char buf2d[10] = "test";
	ft_bzero(buf2d, 10);
	test("ft_bzero: taille complète", buf2d[0] == 0 && buf2d[9] == 0);
	
	// ========== MEMCPY ==========
	section("ft_memcpy");
	char src1[] = "hello world";
	char dest1[20];
	ft_memcpy(dest1, src1, 11);
	test("ft_memcpy: copie normale", !memcmp(dest1, src1, 11));
	ft_memcpy(dest1, "test", 4);
	test("ft_memcpy: copie partielle", !memcmp(dest1, "test", 4));
	char src1b[] = "";
	char dest1b[10] = {0};
	ft_memcpy(dest1b, src1b, 0);
	test("ft_memcpy: taille 0", dest1b[0] == 0);
	char src1c[] = "a";
	char dest1c[10] = {0};
	ft_memcpy(dest1c, src1c, 1);
	test("ft_memcpy: un caractère", dest1c[0] == 'a' && dest1c[1] == 0);
	char src1d[] = "abcdefghijklmnop";
	char dest1d[20] = {0};
	ft_memcpy(dest1d, src1d, 16);
	test("ft_memcpy: chaîne longue", !memcmp(dest1d, src1d, 16));
	
	// ========== MEMCCPY ==========
	section("ft_memccpy");
	char src1e[] = "hello world";
	char dest1e[20] = {0};
	void *ret1e = ft_memccpy(dest1e, src1e, 'o', 11);
	test("ft_memccpy: caractère trouvé", ret1e != NULL && !memcmp(dest1e, "hello", 5));
	char src1f[] = "hello";
	char dest1f[20] = {0};
	void *ret1f = ft_memccpy(dest1f, src1f, 'x', 5);
	test("ft_memccpy: caractère absent", ret1f == NULL && !memcmp(dest1f, src1f, 5));
	char src1g[] = "test";
	char dest1g[20] = {0};
	void *ret1g = ft_memccpy(dest1g, src1g, 't', 4);
	test("ft_memccpy: premier caractère", ret1g != NULL);
	char src1h[] = "hello";
	char dest1h[20] = {0};
	void *ret1h = ft_memccpy(dest1h, src1h, 'o', 4);
	test("ft_memccpy: recherche limitée", ret1h == NULL);
	char src1i[] = "a";
	char dest1i[20] = {0};
	void *ret1i = ft_memccpy(dest1i, src1i, 'a', 1);
	test("ft_memccpy: un caractère", ret1i != NULL);
	
	// ========== MEMMOVE ==========
	section("ft_memmove");
	char buf3[] = "abcdefgh";
	ft_memmove(buf3 + 2, buf3, 4);
	test("ft_memmove: chevauchement", !memcmp(buf3, "ababcdgh", 8));
	char buf4[] = "hello";
	ft_memmove(buf4, buf4 + 2, 3);
	test("ft_memmove: chevauchement inverse", buf4[0] == 'l' && buf4[1] == 'l' && buf4[2] == 'o');
	char buf3b[10] = "test";
	ft_memmove(buf3b, buf3b, 4);
	test("ft_memmove: même adresse", !memcmp(buf3b, "test", 4));
	char buf3c[10] = "test";
	ft_memmove(buf3c, buf3c, 0);
	test("ft_memmove: taille 0", !memcmp(buf3c, "test", 4));
	char buf3d[] = "abcdefgh";
	ft_memmove(buf3d, buf3d + 2, 4);
	test("ft_memmove: chevauchement gauche", !memcmp(buf3d, "cdefefgh", 8));
	
	// ========== STRLCPY ==========
	section("ft_strlcpy");
	char dest2[10];
	test("ft_strlcpy: copie normale", ft_strlcpy(dest2, "hello", 10) == 5 && !strcmp(dest2, "hello"));
	test("ft_strlcpy: buffer trop petit", ft_strlcpy(dest2, "hello world", 5) == 11 && !strncmp(dest2, "hell", 4));
	test("ft_strlcpy: taille 0", ft_strlcpy(dest2, "test", 0) == 4);
	char dest2b[10] = {0};
	test("ft_strlcpy: chaîne vide", ft_strlcpy(dest2b, "", 10) == 0 && dest2b[0] == 0);
	char dest2c[10] = {0};
	test("ft_strlcpy: un caractère", ft_strlcpy(dest2c, "a", 10) == 1 && !strcmp(dest2c, "a"));
	char dest2d[5] = {0};
	test("ft_strlcpy: taille exacte", ft_strlcpy(dest2d, "test", 5) == 4 && !strcmp(dest2d, "test"));
	char dest2e[10] = {0};
	test("ft_strlcpy: taille 1", ft_strlcpy(dest2e, "hello", 1) == 5 && dest2e[0] == 0);
	
	// ========== STRLCAT ==========
	section("ft_strlcat");
	char dest3[20] = "hello";
	test("ft_strlcat: concaténation", ft_strlcat(dest3, " world", 20) == 11 && !strcmp(dest3, "hello world"));
	char dest4[10] = "test";
	test("ft_strlcat: buffer plein", ft_strlcat(dest4, "123456789", 10) == 13);
	char dest3b[20] = "";
	test("ft_strlcat: dest vide", ft_strlcat(dest3b, "hello", 20) == 5 && !strcmp(dest3b, "hello"));
	char dest3c[20] = "hello";
	test("ft_strlcat: src vide", ft_strlcat(dest3c, "", 20) == 5 && !strcmp(dest3c, "hello"));
	char dest3d[10] = "test";
	test("ft_strlcat: taille 0", ft_strlcat(dest3d, "hello", 0) == 5);
	char dest3e[5] = "";
	test("ft_strlcat: buffer trop petit", ft_strlcat(dest3e, "hello", 5) == 5);
	
	// ========== ISALPHA ==========
	section("ft_isalpha");
	test("ft_isalpha: minuscule", ft_isalpha('a') && ft_isalpha('z'));
	test("ft_isalpha: majuscule", ft_isalpha('A') && ft_isalpha('Z'));
	test("ft_isalpha: non-alpha", !ft_isalpha('1') && !ft_isalpha('@') && !ft_isalpha(' '));
	test("ft_isalpha: limites", ft_isalpha('a') && ft_isalpha('z') && ft_isalpha('A') && ft_isalpha('Z'));
	test("ft_isalpha: hors limites", !ft_isalpha('a' - 1) && !ft_isalpha('z' + 1) && !ft_isalpha('A' - 1) && !ft_isalpha('Z' + 1));
	test("ft_isalpha: caractères spéciaux", !ft_isalpha('0') && !ft_isalpha('9') && !ft_isalpha('!'));
	
	// ========== ISDIGIT ==========
	section("ft_isdigit");
	test("ft_isdigit: chiffres", ft_isdigit('0') && ft_isdigit('9'));
	test("ft_isdigit: non-chiffres", !ft_isdigit('a') && !ft_isdigit('@'));
	test("ft_isdigit: tous les chiffres", ft_isdigit('0') && ft_isdigit('1') && ft_isdigit('5') && ft_isdigit('9'));
	test("ft_isdigit: hors limites", !ft_isdigit('0' - 1) && !ft_isdigit('9' + 1));
	test("ft_isdigit: lettres", !ft_isdigit('a') && !ft_isdigit('Z'));
	
	// ========== ISALNUM ==========
	section("ft_isalnum");
	test("ft_isalnum: alpha", ft_isalnum('a') && ft_isalnum('Z'));
	test("ft_isalnum: digit", ft_isalnum('0') && ft_isalnum('9'));
	test("ft_isalnum: non-alnum", !ft_isalnum('@') && !ft_isalnum(' '));
	test("ft_isalnum: combinaisons", ft_isalnum('a') && ft_isalnum('Z') && ft_isalnum('0') && ft_isalnum('9'));
	test("ft_isalnum: caractères spéciaux", !ft_isalnum('!') && !ft_isalnum('@') && !ft_isalnum('#'));
	test("ft_isalnum: espaces", !ft_isalnum(' ') && !ft_isalnum('\t') && !ft_isalnum('\n'));
	
	// ========== ISASCII ==========
	section("ft_isascii");
	test("ft_isascii: caractères valides", ft_isascii(0) && ft_isascii(127) && ft_isascii(65));
	test("ft_isascii: hors limites", !ft_isascii(128) && !ft_isascii(-1));
	test("ft_isascii: limites", ft_isascii(0) && ft_isascii(127));
	test("ft_isascii: valeurs négatives", !ft_isascii(-1) && !ft_isascii(-100));
	test("ft_isascii: valeurs positives hors limites", !ft_isascii(128) && !ft_isascii(255) && !ft_isascii(1000));
	test("ft_isascii: valeurs moyennes", ft_isascii(32) && ft_isascii(64) && ft_isascii(96));
	
	// ========== ISPRINT ==========
	section("ft_isprint");
	test("ft_isprint: imprimables", ft_isprint(' ') && ft_isprint('~') && ft_isprint('A'));
	test("ft_isprint: non-imprimables", !ft_isprint(0) && !ft_isprint(127) && !ft_isprint(31));
	test("ft_isprint: limites", ft_isprint(' ') && ft_isprint('~'));
	test("ft_isprint: hors limites", !ft_isprint(31) && !ft_isprint(127) && !ft_isprint(128));
	test("ft_isprint: caractères de contrôle", !ft_isprint(0) && !ft_isprint(7) && !ft_isprint(13));
	test("ft_isprint: lettres et chiffres", ft_isprint('A') && ft_isprint('z') && ft_isprint('0') && ft_isprint('9'));
	
	// ========== TOUPPER/TOLOWER ==========
	section("ft_toupper / ft_tolower");
	test("ft_toupper", ft_toupper('a') == 'A' && ft_toupper('z') == 'Z');
	test("ft_tolower", ft_tolower('A') == 'a' && ft_tolower('Z') == 'z');
	test("ft_toupper: déjà majuscule", ft_toupper('A') == 'A');
	test("ft_tolower: déjà minuscule", ft_tolower('a') == 'a');
	test("ft_toupper: tous les caractères", ft_toupper('a') == 'A' && ft_toupper('m') == 'M' && ft_toupper('z') == 'Z');
	test("ft_tolower: tous les caractères", ft_tolower('A') == 'a' && ft_tolower('M') == 'm' && ft_tolower('Z') == 'z');
	test("ft_toupper: non-lettres", ft_toupper('1') == '1' && ft_toupper('@') == '@');
	test("ft_tolower: non-lettres", ft_tolower('1') == '1' && ft_tolower('@') == '@');
	
	// ========== STRCHR ==========
	section("ft_strchr");
	test("ft_strchr: caractère trouvé", ft_strchr("hello", 'e') == strchr("hello", 'e'));
	test("ft_strchr: premier caractère", ft_strchr("hello", 'h') == strchr("hello", 'h'));
	test("ft_strchr: dernier caractère", ft_strchr("hello", 'o') == strchr("hello", 'o'));
	test("ft_strchr: caractère absent", ft_strchr("hello", 'x') == strchr("hello", 'x'));
	test("ft_strchr: \\0", ft_strchr("hello", '\0') == strchr("hello", '\0'));
	test("ft_strchr: chaîne vide", ft_strchr("", 'a') == strchr("", 'a'));
	test("ft_strchr: un caractère trouvé", ft_strchr("a", 'a') == strchr("a", 'a'));
	test("ft_strchr: un caractère absent", ft_strchr("a", 'b') == strchr("a", 'b'));
	test("ft_strchr: caractère répété", ft_strchr("hello", 'l') == strchr("hello", 'l'));
	
	// ========== STRRCHR ==========
	section("ft_strrchr");
	test("ft_strrchr: dernière occurrence", ft_strrchr("hello", 'l') == strrchr("hello", 'l'));
	test("ft_strrchr: caractère unique", ft_strrchr("hello", 'h') == strrchr("hello", 'h'));
	test("ft_strrchr: caractère absent", ft_strrchr("hello", 'x') == strrchr("hello", 'x'));
	test("ft_strrchr: \\0", ft_strrchr("hello", '\0') == strrchr("hello", '\0'));
	test("ft_strrchr: chaîne vide", ft_strrchr("", 'a') == strrchr("", 'a'));
	test("ft_strrchr: un caractère", ft_strrchr("a", 'a') == strrchr("a", 'a'));
	test("ft_strrchr: plusieurs occurrences", ft_strrchr("helllo", 'l') == strrchr("helllo", 'l'));
	test("ft_strrchr: premier caractère", ft_strrchr("hello", 'h') == strrchr("hello", 'h'));
	
	// ========== STRNcmp ==========
	section("ft_strncmp");
	test("ft_strncmp: égalité", ft_strncmp("hello", "hello", 5) == 0);
	test("ft_strncmp: différence", ft_strncmp("hello", "world", 5) != 0);
	test("ft_strncmp: comparaison partielle", ft_strncmp("hello", "help", 3) == 0);
	test("ft_strncmp: taille 0", ft_strncmp("hello", "world", 0) == 0);
	test("ft_strncmp: chaîne vide", ft_strncmp("", "", 1) == 0);
	test("ft_strncmp: une chaîne vide", ft_strncmp("", "hello", 5) < 0);
	test("ft_strncmp: taille supérieure", ft_strncmp("hello", "hello", 10) == 0);
	test("ft_strncmp: différence au début", ft_strncmp("abc", "def", 3) != 0);
	test("ft_strncmp: différence à la fin", ft_strncmp("hello", "hellx", 5) != 0);
	
	// ========== MEMCHR ==========
	section("ft_memchr");
	char buf5[] = "hello world";
	test("ft_memchr: caractère trouvé", ft_memchr(buf5, 'o', 11) == memchr(buf5, 'o', 11));
	test("ft_memchr: caractère absent", ft_memchr(buf5, 'x', 11) == memchr(buf5, 'x', 11));
	test("ft_memchr: recherche limitée", ft_memchr(buf5, 'o', 4) == memchr(buf5, 'o', 4));
	char buf5b[] = "test";
	test("ft_memchr: premier caractère", ft_memchr(buf5b, 't', 4) == memchr(buf5b, 't', 4));
	test("ft_memchr: taille 0", ft_memchr(buf5b, 't', 0) == memchr(buf5b, 't', 0));
	char buf5c[] = "a";
	test("ft_memchr: un caractère trouvé", ft_memchr(buf5c, 'a', 1) == memchr(buf5c, 'a', 1));
	test("ft_memchr: valeur 0", ft_memchr(buf5, 0, 11) == memchr(buf5, 0, 11));
	
	// ========== MEMCMP ==========
	section("ft_memcmp");
	test("ft_memcmp: égalité", ft_memcmp("hello", "hello", 5) == 0);
	test("ft_memcmp: différence", ft_memcmp("hello", "world", 5) != 0);
	test("ft_memcmp: taille 0", ft_memcmp("hello", "world", 0) == 0);
	char buf6a[] = "";
	char buf6b[] = "";
	test("ft_memcmp: chaînes vides", ft_memcmp(buf6a, buf6b, 1) == 0);
	test("ft_memcmp: comparaison partielle", ft_memcmp("hello", "help", 3) == 0);
	test("ft_memcmp: différence au début", ft_memcmp("abc", "def", 3) != 0);
	char buf6c[] = "a";
	char buf6d[] = "b";
	test("ft_memcmp: un caractère", ft_memcmp(buf6c, buf6d, 1) != 0);
	
	// ========== STRNSTR ==========
	section("ft_strnstr");
	test("ft_strnstr: sous-chaîne trouvée", ft_strnstr("hello world", "world", 11) != NULL);
	test("ft_strnstr: sous-chaîne absente", ft_strnstr("hello world", "xyz", 11) == NULL);
	test("ft_strnstr: chaîne vide", ft_strnstr("hello", "", 5) != NULL);
	test("ft_strnstr: recherche limitée", ft_strnstr("hello world", "world", 10) == NULL);
	test("ft_strnstr: au début", ft_strnstr("hello world", "hello", 11) != NULL);
	test("ft_strnstr: au milieu", ft_strnstr("hello world", "lo wo", 11) != NULL);
	test("ft_strnstr: taille 0", ft_strnstr("hello", "world", 0) == NULL);
	test("ft_strnstr: chaîne complète", ft_strnstr("hello", "hello", 5) != NULL);
	test("ft_strnstr: un caractère", ft_strnstr("hello", "h", 5) != NULL);
	
	// ========== ATOI ==========
	section("ft_atoi");
	test("ft_atoi: nombre positif", ft_atoi("123") == 123);
	test("ft_atoi: nombre négatif", ft_atoi("-456") == -456);
	test("ft_atoi: avec espaces", ft_atoi("   42") == 42);
	test("ft_atoi: zéro", ft_atoi("0") == 0);
	test("ft_atoi: INT_MAX", ft_atoi("2147483647") == 2147483647);
	test("ft_atoi: INT_MIN", ft_atoi("-2147483648") == -2147483648);
	test("ft_atoi: chaîne invalide", ft_atoi("abc") == 0);
	test("ft_atoi: chaîne vide", ft_atoi("") == 0);
	test("ft_atoi: avec tabs", ft_atoi("\t\n\v\f\r 42") == 42);
	test("ft_atoi: signe +", ft_atoi("+123") == 123);
	test("ft_atoi: plusieurs signes", ft_atoi("--123") == 0);
	test("ft_atoi: nombre avec lettres", ft_atoi("123abc") == 123);
	test("ft_atoi: seulement signe", ft_atoi("-") == 0);
	test("ft_atoi: espaces après", ft_atoi("123 456") == 123);
	
	// ========== CALLOC ==========
	section("ft_calloc");
	int *arr1 = (int *)ft_calloc(5, sizeof(int));
	test("ft_calloc: allocation", arr1 != NULL);
	test("ft_calloc: initialisation à zéro", arr1[0] == 0 && arr1[4] == 0);
	free(arr1);
	char *arr2 = (char *)ft_calloc(10, sizeof(char));
	test("ft_calloc: allocation char", arr2 != NULL && arr2[0] == 0);
	free(arr2);
	void *arr3 = ft_calloc(0, 10);
	test("ft_calloc: taille 0 (nmemb)", arr3 != NULL);
	free(arr3);
	void *arr4 = ft_calloc(10, 0);
	test("ft_calloc: taille 0 (size)", arr4 != NULL);
	free(arr4);
	void *arr5 = ft_calloc(0, 0);
	test("ft_calloc: taille 0 (les deux)", arr5 != NULL);
	free(arr5);
	char *arr6 = (char *)ft_calloc(1, sizeof(char));
	test("ft_calloc: taille 1", arr6 != NULL && arr6[0] == 0);
	free(arr6);
	int *arr7 = (int *)ft_calloc(100, sizeof(int));
	test("ft_calloc: grande allocation", arr7 != NULL && arr7[0] == 0 && arr7[99] == 0);
	free(arr7);
	
	// ========== STRDUP ==========
	section("ft_strdup");
	char *dup1 = ft_strdup("hello");
	test("ft_strdup: duplication normale", dup1 && !strcmp(dup1, "hello"));
	free(dup1);
	char *dup2 = ft_strdup("");
	test("ft_strdup: chaîne vide", dup2 && !strcmp(dup2, ""));
	free(dup2);
	char *dup3 = ft_strdup("a");
	test("ft_strdup: un caractère", dup3 && !strcmp(dup3, "a"));
	free(dup3);
	char *dup4 = ft_strdup("abcdefghijklmnopqrstuvwxyz");
	test("ft_strdup: chaîne longue", dup4 && !strcmp(dup4, "abcdefghijklmnopqrstuvwxyz"));
	free(dup4);
	char *dup5 = ft_strdup("hello\0world");
	test("ft_strdup: avec \\0", dup5 && !strcmp(dup5, "hello"));
	free(dup5);
	
	// ========== SUBSTR ==========
	section("ft_substr");
	char *sub1 = ft_substr("hello world", 0, 5);
	test("ft_substr: début", sub1 && !strcmp(sub1, "hello"));
	free(sub1);
	char *sub2 = ft_substr("hello world", 6, 5);
	test("ft_substr: milieu", sub2 && !strcmp(sub2, "world"));
	free(sub2);
	char *sub3 = ft_substr("hello", 0, 10);
	test("ft_substr: len trop grand", sub3 && !strcmp(sub3, "hello"));
	free(sub3);
	char *sub4 = ft_substr("hello", 10, 5);
	test("ft_substr: start hors limites", sub4 && !strcmp(sub4, ""));
	free(sub4);
	char *sub5 = ft_substr("hello", 0, 0);
	test("ft_substr: len 0", sub5 && !strcmp(sub5, ""));
	free(sub5);
	char *sub6 = ft_substr("hello", 2, 2);
	test("ft_substr: extraction partielle", sub6 && !strcmp(sub6, "ll"));
	free(sub6);
	char *sub7 = ft_substr("", 0, 5);
	test("ft_substr: chaîne vide", sub7 && !strcmp(sub7, ""));
	free(sub7);
	char *sub8 = ft_substr("hello", 0, 1);
	test("ft_substr: un caractère", sub8 && !strcmp(sub8, "h"));
	free(sub8);
	
	// ========== STRJOIN ==========
	section("ft_strjoin");
	char *join1 = ft_strjoin("hello", " world");
	test("ft_strjoin: concaténation", join1 && !strcmp(join1, "hello world"));
	free(join1);
	char *join2 = ft_strjoin("", "world");
	test("ft_strjoin: première vide", join2 && !strcmp(join2, "world"));
	free(join2);
	char *join3 = ft_strjoin("hello", "");
	test("ft_strjoin: deuxième vide", join3 && !strcmp(join3, "hello"));
	free(join3);
	char *join4 = ft_strjoin("", "");
	test("ft_strjoin: deux vides", join4 && !strcmp(join4, ""));
	free(join4);
	char *join5 = ft_strjoin("a", "b");
	test("ft_strjoin: un caractère chaque", join5 && !strcmp(join5, "ab"));
	free(join5);
	char *join6 = ft_strjoin("hello", "world");
	test("ft_strjoin: sans espace", join6 && !strcmp(join6, "helloworld"));
	free(join6);
	
	// ========== STRTRIM ==========
	section("ft_strtrim");
	char *trim1 = ft_strtrim("  hello  ", " ");
	test("ft_strtrim: espaces", trim1 && !strcmp(trim1, "hello"));
	free(trim1);
	char *trim2 = ft_strtrim("xxxhelloxxx", "x");
	test("ft_strtrim: caractères", trim2 && !strcmp(trim2, "hello"));
	free(trim2);
	char *trim3 = ft_strtrim("hello", "xyz");
	test("ft_strtrim: aucun à retirer", trim3 && !strcmp(trim3, "hello"));
	free(trim3);
	char *trim4 = ft_strtrim("", " ");
	test("ft_strtrim: chaîne vide", trim4 && !strcmp(trim4, ""));
	free(trim4);
	char *trim5 = ft_strtrim("   ", " ");
	test("ft_strtrim: seulement espaces", trim5 && !strcmp(trim5, ""));
	free(trim5);
	char *trim6 = ft_strtrim("hello", "");
	test("ft_strtrim: set vide", trim6 && !strcmp(trim6, "hello"));
	free(trim6);
	char *trim7 = ft_strtrim("abc", "abc");
	test("ft_strtrim: tout à retirer", trim7 && !strcmp(trim7, ""));
	free(trim7);
	char *trim8 = ft_strtrim("  a  ", " ");
	test("ft_strtrim: un caractère", trim8 && !strcmp(trim8, "a"));
	free(trim8);
	
	// ========== SPLIT ==========
	section("ft_split");
	char **split1 = ft_split("hello world test", ' ');
	test("ft_split: division basique", split1 && !strcmp(split1[0], "hello") && !strcmp(split1[1], "world"));
	if (split1) {
		int i = 0;
		while (split1[i]) free(split1[i++]);
		free(split1);
	}
	char **split2 = ft_split("a,b,c", ',');
	test("ft_split: avec virgule", split2 && !strcmp(split2[0], "a") && !strcmp(split2[2], "c"));
	if (split2) {
		int i = 0;
		while (split2[i]) free(split2[i++]);
		free(split2);
	}
	char **split3 = ft_split("", ' ');
	test("ft_split: chaîne vide", split3 && split3[0] == NULL);
	free(split3);
	char **split4 = ft_split("hello", ' ');
	test("ft_split: pas de délimiteur", split4 && !strcmp(split4[0], "hello") && split4[1] == NULL);
	if (split4) {
		free(split4[0]);
		free(split4);
	}
	char **split5 = ft_split("  hello  world  ", ' ');
	test("ft_split: espaces multiples", split5 && !strcmp(split5[0], "hello") && !strcmp(split5[1], "world"));
	if (split5) {
		int i = 0;
		while (split5[i]) free(split5[i++]);
		free(split5);
	}
	char **split6 = ft_split("a", 'a');
	test("ft_split: seulement délimiteur", split6 && split6[0] == NULL);
	free(split6);
	
	// ========== ITOA ==========
	section("ft_itoa");
	char *itoa1 = ft_itoa(123);
	test("ft_itoa: positif", itoa1 && !strcmp(itoa1, "123"));
	free(itoa1);
	char *itoa2 = ft_itoa(-456);
	test("ft_itoa: négatif", itoa2 && !strcmp(itoa2, "-456"));
	free(itoa2);
	char *itoa3 = ft_itoa(0);
	test("ft_itoa: zéro", itoa3 && !strcmp(itoa3, "0"));
	free(itoa3);
	char *itoa4 = ft_itoa(2147483647);
	test("ft_itoa: INT_MAX", itoa4 && !strcmp(itoa4, "2147483647"));
	free(itoa4);
	char *itoa5 = ft_itoa(-2147483648);
	test("ft_itoa: INT_MIN", itoa5 && !strcmp(itoa5, "-2147483648"));
	free(itoa5);
	char *itoa6 = ft_itoa(1);
	test("ft_itoa: un", itoa6 && !strcmp(itoa6, "1"));
	free(itoa6);
	char *itoa7 = ft_itoa(-1);
	test("ft_itoa: moins un", itoa7 && !strcmp(itoa7, "-1"));
	free(itoa7);
	char *itoa8 = ft_itoa(999);
	test("ft_itoa: trois chiffres", itoa8 && !strcmp(itoa8, "999"));
	free(itoa8);
	char *itoa9 = ft_itoa(-999);
	test("ft_itoa: trois chiffres négatif", itoa9 && !strcmp(itoa9, "-999"));
	free(itoa9);
	
	// ========== STRMAPI ==========
	section("ft_strmapi");
	char *mapi = ft_strmapi("hello", toupper_mapi);
	test("ft_strmapi: transformation", mapi && !strcmp(mapi, "HELLO"));
	free(mapi);
	char *mapi2 = ft_strmapi("", toupper_mapi);
	test("ft_strmapi: chaîne vide", mapi2 && !strcmp(mapi2, ""));
	free(mapi2);
	char *mapi3 = ft_strmapi("a", toupper_mapi);
	test("ft_strmapi: un caractère", mapi3 && !strcmp(mapi3, "A"));
	free(mapi3);
	char *mapi4 = ft_strmapi("hello", identity_mapi);
	test("ft_strmapi: identité", mapi4 && !strcmp(mapi4, "hello"));
	free(mapi4);
	
	// ========== PUTCHAR_FD ==========
	section("ft_putchar_fd");
	int fd1 = open("/tmp/test_putchar", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ft_putchar_fd('A', fd1);
	close(fd1);
	fd1 = open("/tmp/test_putchar", O_RDONLY);
	char c;
	read(fd1, &c, 1);
	close(fd1);
	test("ft_putchar_fd: caractère normal", c == 'A');
	int fd1b = open("/tmp/test_putchar2", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ft_putchar_fd('z', fd1b);
	close(fd1b);
	fd1b = open("/tmp/test_putchar2", O_RDONLY);
	char c2;
	read(fd1b, &c2, 1);
	close(fd1b);
	test("ft_putchar_fd: minuscule", c2 == 'z');
	int fd1c = open("/tmp/test_putchar3", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ft_putchar_fd('0', fd1c);
	close(fd1c);
	fd1c = open("/tmp/test_putchar3", O_RDONLY);
	char c3;
	read(fd1c, &c3, 1);
	close(fd1c);
	test("ft_putchar_fd: chiffre", c3 == '0');
	
	// ========== PUTSTR_FD ==========
	section("ft_putstr_fd");
	int fd2 = open("/tmp/test_putstr", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ft_putstr_fd("hello", fd2);
	close(fd2);
	fd2 = open("/tmp/test_putstr", O_RDONLY);
	char buf6[10] = {0};
	int len2 = read(fd2, buf6, 10);
	close(fd2);
	test("ft_putstr_fd: chaîne normale", len2 == 5 && !strcmp(buf6, "hello"));
	int fd2b = open("/tmp/test_putstr2", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ft_putstr_fd("", fd2b);
	close(fd2b);
	fd2b = open("/tmp/test_putstr2", O_RDONLY);
	char buf6b_test[10] = {0};
	int len2b = read(fd2b, buf6b_test, 10);
	close(fd2b);
	test("ft_putstr_fd: chaîne vide", len2b == 0);
	int fd2c = open("/tmp/test_putstr3", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ft_putstr_fd("a", fd2c);
	close(fd2c);
	fd2c = open("/tmp/test_putstr3", O_RDONLY);
	char buf6c_test[10] = {0};
	read(fd2c, buf6c_test, 10);
	close(fd2c);
	test("ft_putstr_fd: un caractère", !strcmp(buf6c_test, "a"));
	
	// ========== PUTENDL_FD ==========
	section("ft_putendl_fd");
	int fd3 = open("/tmp/test_putendl", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ft_putendl_fd("test", fd3);
	close(fd3);
	fd3 = open("/tmp/test_putendl", O_RDONLY);
	char buf7[10] = {0};
	read(fd3, buf7, 10);
	close(fd3);
	test("ft_putendl_fd: chaîne normale", !strncmp(buf7, "test\n", 5));
	int fd3b = open("/tmp/test_putendl2", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ft_putendl_fd("", fd3b);
	close(fd3b);
	fd3b = open("/tmp/test_putendl2", O_RDONLY);
	char buf7b[10] = {0};
	read(fd3b, buf7b, 10);
	close(fd3b);
	test("ft_putendl_fd: chaîne vide", buf7b[0] == '\n');
	
	// ========== PUTNBR_FD ==========
	section("ft_putnbr_fd");
	int fd4 = open("/tmp/test_putnbr", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ft_putnbr_fd(12345, fd4);
	close(fd4);
	fd4 = open("/tmp/test_putnbr", O_RDONLY);
	char buf8[10] = {0};
	read(fd4, buf8, 10);
	close(fd4);
	test("ft_putnbr_fd: nombre positif", !strncmp(buf8, "12345", 5));
	int fd4b = open("/tmp/test_putnbr2", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ft_putnbr_fd(-123, fd4b);
	close(fd4b);
	fd4b = open("/tmp/test_putnbr2", O_RDONLY);
	char buf8b[10] = {0};
	read(fd4b, buf8b, 10);
	close(fd4b);
	test("ft_putnbr_fd: nombre négatif", !strncmp(buf8b, "-123", 4));
	int fd4c = open("/tmp/test_putnbr3", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ft_putnbr_fd(0, fd4c);
	close(fd4c);
	fd4c = open("/tmp/test_putnbr3", O_RDONLY);
	char buf8c[10] = {0};
	read(fd4c, buf8c, 10);
	close(fd4c);
	test("ft_putnbr_fd: zéro", buf8c[0] == '0');
	int fd4d = open("/tmp/test_putnbr4", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ft_putnbr_fd(2147483647, fd4d);
	close(fd4d);
	fd4d = open("/tmp/test_putnbr4", O_RDONLY);
	char buf8d[15] = {0};
	read(fd4d, buf8d, 15);
	close(fd4d);
	test("ft_putnbr_fd: INT_MAX", !strncmp(buf8d, "2147483647", 10));
	
	// ========== STRIterI ==========
	section("ft_striteri");
	char str_iteri[] = "hello";
	ft_striteri(str_iteri, to_upper_iteri);
	test("ft_striteri: transformation", !strcmp(str_iteri, "HELLO"));
	char str_iteri2[] = "";
	ft_striteri(str_iteri2, to_upper_iteri);
	test("ft_striteri: chaîne vide", str_iteri2[0] == 0);
	char str_iteri3[] = "a";
	ft_striteri(str_iteri3, to_upper_iteri);
	test("ft_striteri: un caractère", str_iteri3[0] == 'A');
	
	// ========== LISTES CHAÎNÉES (BONUS) ==========
	section("BONUS - Listes chaînées");
	
	t_list *lst1 = ft_lstnew(ft_strdup("first"));
	test("ft_lstnew: création", lst1 != NULL && lst1->next == NULL);
	test("ft_lstnew: content correct", lst1->content != NULL);
	
	t_list *lst2 = ft_lstnew(ft_strdup("second"));
	ft_lstadd_front(&lst1, lst2);
	test("ft_lstadd_front: ajout", lst1 == lst2 && lst1->next != NULL);
	
	test("ft_lstsize: liste de 2", ft_lstsize(lst1) == 2);
	test("ft_lstsize: liste vide", ft_lstsize(NULL) == 0);
	
	t_list *last = ft_lstlast(lst1);
	test("ft_lstlast: dernier élément", last != NULL && last->next == NULL);
	test("ft_lstlast: liste vide", ft_lstlast(NULL) == NULL);
	
	t_list *lst3 = ft_lstnew(ft_strdup("third"));
	ft_lstadd_back(&lst1, lst3);
	test("ft_lstadd_back: ajout", ft_lstsize(lst1) == 3);
	t_list *lst4 = ft_lstnew(ft_strdup("fourth"));
	ft_lstadd_back(&lst1, lst4);
	test("ft_lstadd_back: plusieurs ajouts", ft_lstsize(lst1) == 4);
	
	t_list *lst_empty = NULL;
	t_list *lst5 = ft_lstnew(ft_strdup("first"));
	ft_lstadd_back(&lst_empty, lst5);
	test("ft_lstadd_back: liste vide", lst_empty != NULL && ft_lstsize(lst_empty) == 1);
	ft_lstclear(&lst_empty, free);
	
	t_list *lst_del = ft_lstnew(ft_strdup("test"));
	ft_lstdelone(lst_del, free);
	test("ft_lstdelone: suppression", 1); // Vérifie qu'il n'y a pas de crash
	
	ft_lstclear(&lst1, free);
	test("ft_lstclear: nettoyage complet", lst1 == NULL);
	
	t_list *lst_map1 = ft_lstnew(ft_strdup("hello"));
	t_list *lst_map2 = ft_lstnew(ft_strdup("world"));
	lst_map1->next = lst_map2;
	t_list *new_list = ft_lstmap(lst_map1, map_func, free);
	test("ft_lstmap: création nouvelle liste", new_list != NULL && ft_lstsize(new_list) == 2);
	if (new_list) {
		ft_lstclear(&new_list, free);
	}
	ft_lstclear(&lst_map1, free);
	
	t_list *lst_iter = ft_lstnew(ft_strdup("test"));
	ft_lstiter(lst_iter, print_content);
	test("ft_lstiter: itération", lst_iter != NULL);
	ft_lstclear(&lst_iter, free);
	
	// ========== RÉSULTAT FINAL ==========
	printf("\n%s═══════════════════════════════════════════════════════════════%s\n", "\033[1m", RESET);
	printf("%sRésultat: %s%d/%d tests réussis%s\n", 
		"\033[1m",
		passed == (passed + failed) ? GREEN : RED, 
		passed, passed + failed, RESET);
	printf("%s═══════════════════════════════════════════════════════════════%s\n\n", "\033[1m", RESET);
	
	return (failed > 0);
}
