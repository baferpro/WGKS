#if defined _lk_core_included
  #endinput
#endif
#define _lk_core_included

public SharedPlugin __pl_lk_core = 
{
	name = "lk",
	file = "lk_core.smx",
#if defined REQUIRE_PLUGIN
    required = 1
#else
    required = 0
#endif
};

#if !defined REQUIRE_PLUGIN
public void __pl_lk_core_SetNTVOptional()
{
	MarkNativeAsOptional("LK_GetMainMenuTitle");
	MarkNativeAsOptional("LK_GetCurrency");
	MarkNativeAsOptional("LK_GetDatabase");
	MarkNativeAsOptional("LK_ShowMainMenu");
	MarkNativeAsOptional("LK_GameCMS_Mode");
	MarkNativeAsOptional("LK_GetVersion");
	MarkNativeAsOptional("LK_GetClientCash");
	MarkNativeAsOptional("LK_SetClientCash");
	MarkNativeAsOptional("LK_AddClientCash");
	MarkNativeAsOptional("LK_TakeClientCash");
	MarkNativeAsOptional("LK_ResetClientCash");
	MarkNativeAsOptional("LK_GetClientAllCash");
	MarkNativeAsOptional("LK_AddClientAllCash");
	MarkNativeAsOptional("LK_ResetClientAllCash");
	MarkNativeAsOptional("LK_RegisterItem");
	MarkNativeAsOptional("LK_UnRegisterItem");
	MarkNativeAsOptional("LK_LogMessage");
	MarkNativeAsOptional("LK_PrintToChat");
	MarkNativeAsOptional("LK_PrintToChatAll");
}
#endif

/*
 * �������� Title �������� ���� c �������� ������, ������ �� ��������
 *
 * @param iClient 			������ ������.
 * @param sTitle			�����, � ������� ����� ������� ���������.
 * @param iMaxLength		������ ������.
 *
 * @return
 * true - �������.
 * false - ����� �� ������ ��������(��� ��� �� � ����)
 */
native bool LK_GetMainMenuTitle(int iClient, char[] sTitle, int iMaxLength);

/*
 * �������� Currency(������) ������������ ��� ������, ������ �� ��������
 *
 * @param iClient 			������ ������.
 * @param sTitle			�����, � ������� ����� ������� ���������.
 * @param iMaxLength		������ ������.
 *
 * @return
 * true - �������.
 * false - ����� �� ������ ��������(��� ��� �� � ����)
 */
native bool LK_GetCurrency(int iClient, char[] sTitle, int iMaxLength);

/*
 * ���������� Database(���� ������), ��� ������ �������, ���� ��� ����������
 */
native Database LK_GetDatabase();

/*
 * ������� ������� ����
 */
native int LK_ShowMainMenu(int iClient);

/*
 * ��������� � ����� ������ �������� ����
 *
 * @return
 *
 * false - ��� ��������� ������
 * true - ����� ������������� � GameCMS
 */
native bool LK_GameCMS_Mode();

/*
 * ��������� ������ ���� ������(int)
 *
 * @return value
 *
 */
native int LK_GetVersion();

/*
 * ��������� ���������� ����� �� ����� � ������
 *
 * @param iClient 			������ ������.
 * @return value
 *
 */
native int LK_GetClientCash(int iClient);

/*
 * ���������� �������� ����� �� ����� � ������
 *
 * @param iClient 			������ ������.
 * @param amount 			���-�� �����
 *
 */

native int LK_SetClientCash(int iClient, int amount);

/*
 * �������� �������� ����� �� ���� ������
 *
 * @param iClient 			������ ������.
 * @param amount 			���-�� �����
 *
 */

native int LK_AddClientCash(int iClient, int amount);

/*
 * ������ �������� ����� �� ����� ������
 *
 * @param iClient 			������ ������.
 * @param amount 			���-�� �����
 */

native int LK_TakeClientCash(int iClient, int amount);

/*
 * ��������� ���������� ����� �� ����� � ������
 *
 * @param iClient 			������ ������.
 * @noreturn
 */

native int LK_ResetClientCash(int iClient);

/*
 * ��������� ���������� ����� �� ��� �����
 * AllCash - ���������� ���� ����� "�����������" ������� �� ��� �����(���� �� ��������)
 *
 * @param iClient 			������ ������.
 * @return value
 */

native int LK_GetClientAllCash(int iClient);

/*
 * �������� ���������� ����� �� ��� �����
 *
 * @param iClient 			������ ������.
 * @param amount 			���-�� �����
 */

native int LK_AddClientAllCash(int iClient, int amount);

/*
 * ��������� �������� � ������ (allcash)
 *
 * @param iClient 			������ ������.
 * @return value
 */

native int LK_ResetClientAllCash(int iClient);

/**
 *
 * ������� ������� (����� � !lk ����)
 *
 * sItemName - ���������� ���, �������� "top10", ���� ���� ����� ����������� � lk.phrases.txt
 * RegisterCallback - Callback ������, ����� ����� ����� � ������� ���� �� ��� sItemName
 *
**/
native void LK_RegisterItem(const char[] sItemName, RegisterCallback callback);

/**
 *
 * RegisterCallback
 *
 * @param iClient 			������ ������.
 * @param iItemID 			���������� ����� � ������� ���� (��� ������ ����������)
 * @param sItemName 		���������� ���, �������� "top10", ���� ���� ����� ����������� � lk.phrases.txt
 *
**/
typedef RegisterCallback = function void (int iClient, int iItemID, const char[] sItemName);

/**
 *
 * ������� ������� �� !lk ����
 *
**/
native int LK_UnRegisterItem(const char[] sItemName);

/**
 *
 *	���������� ��������� � ���.
 *	-
 * @param sMessage			C��������.
 * @param ...				���������.
 *
*/
native int LK_LogMessage(const char[] sMessage, any:...);

/**
 *
 *	�������� � ��� ���� �������(�������� �������� �� �� ����� ����, ��� ��� � ���� ��������� ��������� �� �����)
 *  p.s. sMessage ��� �������� � ���� Chat_Prefix �� ����� ��������, lk.prhases.txt
 *	-
 * @param sMessage			C��������.
 * @param ...				���������.
 *
*/
native int LK_PrintToChat(int iClient, const char[] sMessage, any:...);

/**
 *
 *	�������� � ��� ���� �������(�������� �������� �� �� ����� ����, ��� ��� � ���� ��������� ��������� �� �����)
 *  p.s. sMessage ��� �������� � ���� Chat_Prefix �� ����� ��������, lk.prhases.txt
 *	-
 * @param sMessage			C��������.
 * @param ...				���������.
 *
**/
native int LK_PrintToChatAll(const char[] sMessage, any:...);

/**
 *
 * ����� ������� ����������� ����
 *	-
 * @param iClient 			������ ������.
 * @param szAuth			SteamID.
 * @param sKey				����.
 *
**/
forward void LK_OnKeyWasUsed(int iClient, const char[] szAuth, const char[] sKey);

/**
 *
 *	���������� ����� ���� LK �����������.
 *
*/
forward void LK_OnLoaded();