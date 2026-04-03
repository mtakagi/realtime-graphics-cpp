import sys
import subprocess
import os

def main():
    if len(sys.argv) != 3:
        print("Usage: python golden_test.py <executable> <golden_file>")
        sys.exit(1)

    exe_path = sys.argv[1]
    golden_path = sys.argv[2]

    # 実行ファイルを実行し、標準出力(stdout)のみをキャプチャする（stderrの進捗バーは無視される）
    try:
        result = subprocess.run([exe_path], capture_output=True, text=True, check=True)
        actual_output = result.stdout
    except subprocess.CalledProcessError as e:
        print(f"Error running {exe_path}: {e}")
        sys.exit(1)

    # ゴールデンファイル（正解ファイル）が存在するか確認
    if not os.path.exists(golden_path):
        print(f"FAIL: Golden file not found: {golden_path}")
        print(f"To generate it, run: {exe_path} > {golden_path}")
        sys.exit(1)

    # ゴールデンファイルを読み込む
    with open(golden_path, 'r', encoding='utf-8') as f:
        expected_output = f.read()

    # 改行コードの違い(\r\n と \n)を吸収して比較
    if actual_output.replace('\r\n', '\n') == expected_output.replace('\r\n', '\n'):
        print("PASS: Output matches golden file.")
        sys.exit(0)
    else:
        print("FAIL: Output does not match golden file.")
        # 実際の出力を保存して確認できるようにするなどの拡張も可能です
        sys.exit(1)

if __name__ == "__main__":
    main()