
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 未使用引数の警告対策
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(nCmdShow);

	// デバッグ情報用ログファイルの出力の抑制
	SetOutApplicationLogValidFlag(FALSE);

	ChangeWindowMode(TRUE);	          // ウインドウモードで実行
	SetMainWindowText("test window");    // ウインドウタイトルの設定
//	SetWindowIconID(IDI_ICON1);       // ウインドウアイコンの設定

	// 初期状態の画面モードの設定
	SetGraphMode(1280, 720, 32);

	// DXライブラリの初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;    // エラーが起きたら直ちに終了
	}

	// 描画先を裏画面に設定
	SetDrawScreen(DX_SCREEN_BACK);

	// DXライブラリの終了処理
	DxLib_End();

	return 0;
}